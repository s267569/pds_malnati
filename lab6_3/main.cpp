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
    int cycles = 25;
    for (int i=0; i<cycles; i++){
        std::packaged_task<void()> task{std::bind(f, i)};
        return_values.emplace_back(task.get_future());
        tp.execute(std::move(task));
        std::cout << "Inserted task number " << i << std::endl;
    }

    for(std::future<void> & future: return_values){
        future.wait();
        std::cout << "Future (unknown number) finished\n";
    }
    tp.finish();

    try{
        std::packaged_task<void()> task{std::bind(f,-1)};
        tp.execute(std::move(task));
    }catch (std::logic_error& le){
        std::cout << "Logic error occurred: " << le.what() << std::endl;
    }catch(...){ //catturiamo qualsiasi tipo di eccezione
        std::cout << "Generic error occurred" << std::endl;
    }
    std::cout << "Main program finished\n";
    return 0;
}
