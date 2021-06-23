//
// Created by Domenico Cefalo on 23/06/21.
//

#ifndef LAB6_3_THREADPOOL_H
#define LAB6_3_THREADPOOL_H
#include <mutex>
#include <condition_variable>
#include <future>
#include <deque>

class ThreadPool {
    int min_threads_,max_threads_,max_size_;
    int active_threads;
    std::deque<std::packaged_task<void()>> tasks;
    std::mutex m_tasks;
    std::condition_variable cv_task_ready;
public:
    ThreadPool() = delete;
    ThreadPool(int min_threads, int max_threads, int max_size);
    void execute(std::packaged_task<void()> task);
    void finish();
    ~ThreadPool();

};


#endif //LAB6_3_THREADPOOL_H
