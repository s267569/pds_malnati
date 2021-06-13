#include <iostream>
#include <future>
#include <string>

int task1() { //prima fase del calcolo
    std::cout << "task1()" << std::endl;
    int a=1;
    return a;
}

int task2(std::shared_future<int>){ //seconda fase
    std::cout << "task2()" << std::endl;
    int count=1;
    for (int i=0; i<100; i++){
        count+=1;
    }
    return count;
}
int task3(std::shared_future<int>) { //terza fase
    std::cout << "task3()" << std::endl;
    int b = 3;
    return b;
}

int main() {
    std::shared_future<int> f1 = std::async(std::launch::async, task1).share();
    std::future<int> f2 = std::async(task2, f1);
    std::future<int> f3 = std::async(task3, f1);

    int str = f2.get();
    int d = f3.get();

    int somma = str+d;
    std::cout << "Somma: " << somma << std::endl;
    return 0;
}
