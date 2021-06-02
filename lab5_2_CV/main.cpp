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
