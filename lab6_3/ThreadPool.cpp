//
// Created by Domenico Cefalo on 23/06/21.
//
#include "ThreadPool.h"

ThreadPool::ThreadPool(int min_threads, int max_threads, int max_size) : min_threads_(min_threads),max_threads_(max_threads),max_size_(max_size){
    active_threads=0;
    active=true;
    auto execution = [this](){
            std::unique_lock ul{m_tasks};
            while(active || !tasks.empty()) {
                //operare sulla coda è la sezione critica, l'operazione sul packaged_trask invece è una operazione che
                //posso eseguire contemporaneamente agli altri
                cv_task_ready.wait(ul,[&]() { return !tasks.empty()||!active;}); //catturo per reference: catturo tutto ciò di prima per reference.
                if(!active && tasks.empty()) break;
                //potevo anche catturare anche solo &tasks.
                //La pop in C++ va sempre fatta in due passaggi
                std::packaged_task<void()> task_to_execute = std::move(
                        tasks.front()); //packaged_task non è copiabile ma solo movibile
                tasks.pop_front();
                cv_queue.notify_one();
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
    if(active==false) throw  std::logic_error("Finish was called before, impossibile to add a task");
    cv_queue.wait(ul, [&](){return tasks.size()<max_size_;});
    tasks.push_back(std::move(task));
    cv_task_ready.notify_one();
    ul.unlock(); //anche se non serve perché subito dopo vi è la chiusura graffe
}

void ThreadPool::finish(){
    std::unique_lock ul{m_tasks};
    active = false;
    cv_task_ready.notify_all();
    ul.unlock(); //Attenzione è molto importante per il cv.wait(...) della funzione di sopra
    for(std::thread& t:executors){
        t.join();
    }
}

ThreadPool::~ThreadPool(){

}
