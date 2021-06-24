#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include "ThreadPool.h"

int main() {
    std::cout << "Starting the main program" << std::endl;
    ThreadPool tp{2,5,10};
    auto f = [](int progressive_task){
        std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(rand()%1000));
    };
    std::vector<std::future<void>> return_values;
    int cycles = 4;
    for (int i=0; i<cycles; i++){
        std::packaged_task<void()> task{std::bind(f, i)};
        return_values.emplace_back(task.get_future());
        tp.execute(std::move(task));
    }

    for(std::future<void> & future: return_values){
        future.wait();
        std::cout << "Future (unknows number) finished\n";
    }

    std::cout << "Main program finished\n";
    return 0;
}
