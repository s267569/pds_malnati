#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

class CountingSemaphore{
    int count;
    std::mutex m;
    std::condition_variable cv;
public:
    CountingSemaphore(int n){
        count = n;
    }
    CountingSemaphore(){
        count = 0;
    }
    void acquire(){
        std::unique_lock<std::mutex> lk(m);
        if(count <=0){
            cv.wait(lk);
        }else{
            count --;
            return;
        }
    }
    void release(){
        std::lock_guard<std::mutex> lg(m);
        count++;
        cv.notify_one();
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
