#include <iostream>
#include <thread>
#include <mutex>

int n = 0;
std::mutex m;

void f1(){
    for(int i=0; i<1000000; i++){
        std::lock_guard<std::mutex> lg(m);
        //m.lock();
        n++;
        //m.unlock();
    }
}

void f2(){
    for(int i=0; i<1000000; i++){
        std::lock_guard<std::mutex> lg(m);
        //m.lock();
        n++;
        //m.unlock();
    }
}


int main() {
    std::thread t1(f1);
    std::thread t2(f2);

    //l'operazione di seguito blocca finché t1 e t2 non hanno finito
    t1.join();
    t2.join();

    std::cout << "Alla fine n vale : " << n << std::endl;
    return 0;
}
