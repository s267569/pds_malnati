#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

int n; //numero thread bloccati
class BarrieraCiclica{
    int countT;
    std::condition_variable cv;
    std::mutex m;
public:
    BarrieraCiclica(int countT){
        this->countT=countT;
    }
    void attendi(){
        //blocca il thread chiamante fino a che altri N_1 thread non risultano bloccato insieme ad esso
        if(n == countT-1){
            std::lock_guard<std::mutex> lk(m);
            n=0; //ora non sarà nessuno bloccato
            cv.notify_all();
            return;
        }
        else{
            std::unique_lock<std::mutex> ul(m);
            n++;
            while(n!=countT-1)
                cv.wait(ul);
        }
    }
};
int main() {
    BarrieraCiclica bc(3);
    std::vector<std::thread> v;
    for(int i=0; i<5; i++){
        std::thread t([i, &bc](){
            std::cout << "Thread " << i << " started" << std::endl;
            bc.attendi();
            std::cout << "Thread " << i << " finished" << std::endl;
        });
        v.emplace_back(std::move(t));
    }

    for (int i=0; i<v.size(); i++){
        v[i].join();
    }


    return 0;
}
