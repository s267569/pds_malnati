//
// Created by Domenico Cefalo on 23/06/21.
//

#ifndef LAB6_3_THREADPOOL_H
#define LAB6_3_THREADPOOL_H

#include <mutex>
#include <condition_variable>
#include <future>
#include <deque>
#include <vector>
#include <thread>

class ThreadPool {
    int min_threads_,max_threads_,max_size_;
    int active_threads;
    bool active;
    std::deque<std::packaged_task<void()>> tasks;
    std::mutex m_tasks;
    std::condition_variable cv_task_ready;
    std::condition_variable cv_queue;
    std::vector<std::thread> executors;

public:
    ThreadPool() = delete;
    ThreadPool(int min_threads, int max_threads, int max_size);
    void execute(std::packaged_task<void()>&& task); //Lo marchiamo con RVALUE reference in modo che anche il main che ci chiama deve sapere che deve muoverlo e non copiarlo
    void finish();
    ~ThreadPool();

};
#endif //LAB6_3_THREADPOOL_H
