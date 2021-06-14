#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <functional>

class Synchronizer {
    std::function<void(float, float)> m_process;
    std::mutex lock;
    std::condition_variable cv;
    bool first, second;
    float otherValue;
public:
    Synchronizer(std::function<void(float d1, float d2)> process):
        first(false), second(false), otherValue(0), m_process(process){}

    void dataFromFirstPort(float d1){

    }

    void dataFromSecondPort(float d2){

    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
