#include <iostream>
#include <thread>
#include <mutex>
#include <time.h>

class DurationLogger{
    clock_t time;
    std::string name;
public:
    DurationLogger(const std::string& name){
        std::cout << "sono nel costruttore di DurationLogger() @" << this << std::endl;
        time = clock();
        this->name = name;
    }
    ~DurationLogger(){
        std::cout << "distruggo DurationLogger() @" << this << std::endl;
    }
    std::string getName(){
        return this->name;
    }
    clock_t getTime(){
        return clock()-this->time;
    }
};

std::mutex mf1;
std::mutex mf2;

int count = 0;
int tot=0;

void f1(){
    for(int i=0; i<100000; i++){
        mf1.lock();
        count++;
        mf2.unlock();
    }
}

void f2(){
    for(int i=0; i<100000; i++) {
        mf2.lock();
        int res = count % 43;
        tot += res;
        mf1.unlock();
    }
}

int main() {
    DurationLogger dl{"tempi thread"};
    std::cout << dl.getName() << std::endl;
    std::thread t1(f1);
    std::thread t2(f2);

    mf1.lock();

    t1.join();
    t2.join();

    std::cout << "Alla fine count = " << count << std::endl;
    std::cout << "Alla fine tot = " << tot << std::endl;

    std::cout << dl.getTime() << std::endl;
    return 0;
}
