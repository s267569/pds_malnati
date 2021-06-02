#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

const int max_n=1000000;
const int rest = 43;
int count = 0;
int tot=0;

std::mutex m;
std::condition_variable cv;

void f1(){
    for(int i=0; i<max_n; i++){
        std::lock_guard<std::mutex> lg(m);
        count++;
        cv.notify_one();
    }
}

void f2(){
    for(int i=0; i<max_n; i++) {
        std::unique_lock<std::mutex> ul(m);
        cv.wait(ul);
        int res = count%rest;
        tot+=res;
        ul.unlock();
    }
    std::cout << "Final value of sum of the rests: " << tot << std::endl;
}
/*
void cond_var_flow(){
    std::mutex m;
    std::condition_variable cv;

    auto f1 = [](){
        for(int i=0; i<max_n; i++){
            count++;
        }
    };

}
*/
int main() {

    return 0;
}
