#include <iostream>
#include <future>
#include <string>
#include <thread>

void func(std::promise<std::string> p){
    try{
        std::string result = "...";
        p.set_value(std::move(result));
    } catch(...){
        p.set_exception(std::current_exception());
    }
}

int main() {
    std::promise<std::string> p;
    std::future<std::string> f = p.get_future();

    std::thread t(func, std::move(p));
    t.detach();

    std::string res = f.get();
    return 0;
}
