#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <shared_mutex>

int n; //numero thread bloccati
class BarrieraCiclica{
    int countT;
    std::condition_variable cv;
    std::mutex m;
    std::shared_mutex m_turno;
    bool finito;
    int svegliati=0;
    bool turno;
public:
    BarrieraCiclica(int countT){
        this->countT=countT;
        turno = true;
    }
    void attendi(){
        //blocca il thread chiamante fino a che altri N_1 thread non risultano bloccato insieme ad esso

        std::shared_lock<std::shared_mutex> uk_turno(m_turno);
        cv.wait(uk_turno, [this](){return turno==true;});
        if(n == countT-1){
            std::lock_guard<std::mutex> lk(m);
            cv.notify_all();
            return;
        }
        else{
            std::unique_lock<std::mutex> ul(m);
            n++;
            while(n!=countT-1){
                cv.wait(ul);
            }
            svegliati++;
            if(svegliati==n)
                finito=true;

            if(finito==true) {
                n = 0;
                finito=false;
            }
        }
    }
};
int main() {
    std::mutex m_print;
    BarrieraCiclica bc(7);
    std::vector<std::thread> v;
    for(int i=0; i<14; i++){
        std::thread t([i, &bc, &m_print](){
            std::unique_lock<std::mutex> ul_print(m_print);
            std::cout << "Thread " << i << " started" << std::endl;
            ul_print.unlock();

            bc.attendi();

            ul_print.lock();
            std::cout << "Thread " << i << " finished" << std::endl;
            ul_print.unlock();
        });
        v.emplace_back(std::move(t));
    }

    for (int i=0; i<v.size(); i++){
        v[i].join();
    }
    return 0;
}
