#include <iostream>
#include <thread>
#include <mutex>

int n = 0;



int main() {
    std::thread t1(f1);
    std::thread t2(f2);

    t1.join();
    t2.detach();

    std::cout << "Alla fine n vale : " << n << std::endl;
    return 0;
}
