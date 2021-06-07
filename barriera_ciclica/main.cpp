#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

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
        if(n == countT){
            std::lock_guard<std::mutex> lk(m);
            n=0; //ora non sarà nessuno bloccato
            cv.notify_all();
            return;
        }
        if(n<=countT-1){
            std::unique_lock<std::mutex> ul(m);
            n++;
            cv.wait(ul); //manca controllo condizione spuria (forse non serve)
        }
    }
};
int main() {
    BarrieraCiclica bc(3);

    return 0;
}
