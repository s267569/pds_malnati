#include <iostream>
#include <thread>
#include <mutex>

//CountDownLatch -- Java Util Cuncurrent

class CountDownLatch {
    int count;
    std::mutex m;
public:
    CountDownLatch(int initialCount): count(initialCount){}
    void await(){};

    void countDown(){
        std::lock_guard<std::mutex> lg(m);
        if(count>0) count--;

    }
};










int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
