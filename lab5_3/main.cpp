#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <string>
#include <fstream>
#include <vector>
class CountingSemaphore{
    int count;
    std::mutex m;
    std::condition_variable cv;
public:
    CountingSemaphore(int n){
        count = n;
    }
    CountingSemaphore(){
        count = 0;
    }
    void acquire(){
        std::unique_lock<std::mutex> lk(m);
        while(count <=0){
            cv.wait(lk);
        }
        if (count >0){
            count --;
            return;
        }
    }
    void release(){
        std::lock_guard<std::mutex> lg(m);
        count++;
        cv.notify_one();
    }
};

void find_p (std::string str, std::ifstream ifs, CountingSemaphore s, std::mutex &mkfind){
    s.acquire();
    char line[200];
    std::unique_lock<std::mutex> lkfind(mkfind);
    if(ifs.getline(line, 200)){
        lkfind.unlock();
        std::string s = line;
        s.find(str);
        std::cout << "Trovata" << std::endl;
    }
    s.release();
}
int main() {
    CountingSemaphore cs(4);
    std::string line = "ciao";
    std::mutex mkfind;
    std::ifstream ifs("/Users/domenicocefalo/Dropbox (Politecnico Di Torino Studenti)/Programmazione di sistema/Malnati/pds_malnati/lab5_3/test.txt");

    std::thread t1(find_p, line, ifs, cs, std::ref(mkfind));


    return 0;
}
