#include <iostream>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <future>
#include <functional>
#include <vector>
#include <memory>
#define MAX_N 3

class threadPool{
    std::vector<std::thread> v_thread; //thread pool
    std::queue<std::packaged_task<void()>> q_task;
    std::mutex m; //used to push/pop to/from queue
    std::condition_variable cv; //used to notify threads about available tasks
    int numThreads;
    int counter;
    bool ended;
    threadPool(const threadPool&) = delete;
    threadPool &operator=(const threadPool&) = delete;

public:
    //std::thread::hardware_concurrency()
    threadPool(int N):numThreads(std::thread::hardware_concurrency()), ended(false), counter(0){

        std::cout<<"Max number of threads (available cores) = "<<numThreads<<std::endl;
        for(int i=0;i<3;i++){
            v_thread.push_back(std::thread([this](){
                while(true){
                    std::unique_lock<std::mutex> ul(m);
                    // se ci sono task nella coda OPPURE il ciclo è terminato (quindi ended==true)
                    // non aspetto
                    // se devo avere un max di MAX_N di esecuzioni concorrenti: !q_task.empty() && counter<MAX_N
                    //cv.wait(ul, [this](){return ((!q_task.empty() && counter<MAX_N) || !ended);});
                    cv.wait(ul, [this](){return (!q_task.empty() || ended);});
                    if(ended) break; //se loop terminato (ended==true), break, esco dal while

                    //counter++;
                    std::cout << "Inserisco task nel packaged"<<std::endl;
                    //prendo un task dalla coda e lo inserisco nel packaged_task
                    std::packaged_task<void()> task = std::move(this->q_task.front());
                    //estraggo dalla coda il task
                    q_task.pop();
                    std::cout << "Estraggo task dalla coda"<<std::endl;
                    ul.unlock();

                    task(); //eseguo task;
                    std::cout<<" task ESEGUITO"<<std::endl;
                    ul.lock();
                    //counter--;
                    cv.notify_one();

                }
            }));
        }
    }

    ~threadPool(){
        quit();
    }

    void quit(){
        std::unique_lock l(m);
        ended = true;
        cv.notify_all();
        for(auto it=v_thread.begin(); it!=v_thread.end(); it++){
            if(it->joinable()) {
                l.unlock(); //rilascio lock per far concludere i thread del pool non ancora terminati
                it->join();
                l.lock();
                std::cout<<"distruttore @ "<<this<<"ha finito un thread"<<std::endl;

            }
        }
    }

    std::future<void> sumbit(std::function <void()> f){
        std::lock_guard l(m);
        std::packaged_task<void()> task(f); //passo la funzione al packaged_task
        std::cout<<" Packaged_task CREATO"<<std::endl;
        // prendo il future dal task prima di inserire il task (tramite move) nella coda
        std::future<void> result = task.get_future();
        std::cout<<" future CREATO"<<std::endl;
        q_task.push(std::move(task));
        std::cout<<" vettore di task RIMEPITO"<<std::endl;
        cv.notify_one(); //notifico thread che è disponibile un nuovo task
        return  result;

    }


};
void fun(){
    std::cout << "Function executed!"<<std::endl;
}

int main() {
    threadPool threadPool(10);
    std::function<void()> f = fun;
    for(int i=0;i<10;i++) {
        std::future<void> result = threadPool.sumbit(f);
        //std::cout<<"Result = "<<result.get()<<" Iter = "<< i<<std::endl;
    }


    return 0;
}
