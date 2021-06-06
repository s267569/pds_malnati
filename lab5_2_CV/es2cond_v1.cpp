#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

const int max_n=100000;
const int rest = 43;
int tot=0;

std::mutex m;
std::condition_variable cv;
//di seguito le variabili condivise
int count = 0;
bool ready = false;

void f1(){
    for(int i=0; i<max_n; i++){

        //il while di seguito è molto pericolosa, la soluzione sarebbe metterlo dopo riga 22
        while(ready){
            std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(rand() % 1000));
        }
        std::cout << "f1()" << std::endl;
        std::lock_guard<std::mutex> lg(m);
        count++;
        ready=true;
        cv.notify_one();
    }
}

void f2(){
    for(int i=0; i<max_n; i++) {
        std::unique_lock<std::mutex> ul(m);
        if (ready == false) //dato non pronto ==> ci mettiamo in attesa
            cv.wait(ul, [](){return ready;}); //è = a dire return ready==true;
        std::cout << "f2()" << std::endl;
        int res = count%rest;
        tot+=res;
        ready = false;
        ul.unlock();
    }
    std::cout << "Final value of sum of the rests: " << tot << std::endl;
}

void cond_var_flow(){
    std::thread t1(f1);
    std::thread t2(f2);

    t1.join();
    t2.join();
}

int main() {
    cond_var_flow();
    return 0;
}
