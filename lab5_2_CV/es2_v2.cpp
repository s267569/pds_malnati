#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

const int max_n=100000;
const int rest = 43;

void cond_var_flow(){
    std::mutex m;
    std::condition_variable p_c, c_p; //p_c=producer_consumer e viceversa
    int count = 0;

    auto producer = [&count, &m, &p_c, &c_p](){
        for (int i=0; i< max_n; i++){
            std::unique_lock ul{m};
            count++;
        }
    };

    auto consumer = [&count, &m, &p_c, &c_p](){

    };

    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

}

int main() {
    cond_var_flow();
    return 0;
}
