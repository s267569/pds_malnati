#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include "DurationLogger.h"

const int max_n = 1000000;
const int rest = 43;

void cond_var_flow() {
    std::mutex m;
    std::condition_variable cv;
    int count = 0;
    bool ready = false;

    auto producer = [&count, &ready, &m, &cv] () {
        for (int i=0; i<max_n; i++) {
            std::unique_lock ul{m};
            count++;
            ready = true;
            cv.notify_one();
            cv.wait(ul, [&ready](){return !ready;});
        }
    };
    auto consumer = [&count, &ready, &m, &cv] () {
        int tot_res = 0;
        for (int i=0; i<max_n; i++) {
            std::unique_lock ul{m};
            cv.wait(ul, [&ready](){return ready;});
            tot_res += count % rest;
            ready = false;
            cv.notify_one();
        }
        std::cout << "Final value of sum of the rests: " << tot_res << std::endl;
    };

    DurationLogger log{"double_condition_variable"};

    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();
}

int main() {
    cond_var_flow();
    return 0;
}
