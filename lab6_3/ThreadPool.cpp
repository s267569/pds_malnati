//
// Created by Domenico Cefalo on 23/06/21.
//

#include "ThreadPool.h"

ThreadPool::ThreadPool(int min_threads, int max_threads, int max_size) : min_threads_(min_threads),max_threads_(max_threads),max_size_(max_size){
    active_threads=0;
    active=true;
    auto execution = [this](){
            while(active) {
                //operare sulla coda è la sezione critica, l'operazione sul packaged_trask invece è una operazione che
                //posso eseguire contemporaneamente agli altri
                std::unique_lock ul{m_tasks};
                cv_task_ready.wait(ul,[&]() { return !tasks.empty()||!active;}); //catturo per reference: catturo tutto ciò di prima per reference.
                if(!active) break;

                //potevo anche catturare anche solo &tasks.
                //La pop in C++ va sempre fatta in due passaggi
                std::packaged_task<void()> task_to_execute = std::move(
                        tasks.front()); //packaged_task non è copiabile ma solo movibile
                tasks.pop_front();
                active_threads++;
                ul.unlock(); //Non abbiamo più bisogno di operare in maniera protetta
                task_to_execute();
                ul.lock();
                active_threads--;
            }
    };
    for (int i=0; i<min_threads; i++){
        executors.emplace_back(std::thread(execution)); //con emplace_back si poteva anche solo scrivere executors.emplace_back(execution)
    }
}
void ThreadPool::execute(std::packaged_task<void()>&& task){
    std::unique_lock ul(m_tasks);
    tasks.push_back(std::move(task));
    cv_task_ready.notify_one();
    ul.unlock(); //anche se non serve perché subito dopo vi è la chiusura graffe
}
void ThreadPool::finish(){
    std::unique_lock ul{m_tasks};
    active = false;
    cv_task_ready.notify_all();
    for(std::thread& t:executors){
        t.join();
    }
}
ThreadPool::~ThreadPool(){

}
