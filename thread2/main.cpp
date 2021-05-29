#include <iostream>
#include <thread>
#include <mutex>

int n = 0;
std::mutex m;
void f1(){
    for(int i=0; i< 10000000; i++){
        std::lock_guard<std::mutex> lg(m);
        n++;
    }
}

void f2(){
    for(int i=0; i< 10000000; i++){
        std::lock_guard<std::mutex> lg(m);
        n++;
    }
}

std::thread createThead() {
    std::thread t(f1);
    return std::move(t);
}
int main() {
    std::thread t1 = createThead();
    std::thread t2 = createThead();

    t1.detach();
    t2.detach();

    std::cout << "Alla fine n vale : " << n << std::endl;
    return 0;
}
