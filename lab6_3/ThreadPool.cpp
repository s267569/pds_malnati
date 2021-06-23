//
// Created by Domenico Cefalo on 23/06/21.
//

#include "ThreadPool.h"

ThreadPool::ThreadPool(int min_threads, int max_threads, int max_size) : min_threads_(min_threads),
                                                                        max_threads_(max_threads),
                                                                        max_size_(max_size)     {
    active_threads=0;

}
void execute(std::packaged_task<void()> task);
void finish();
ThreadPool::~ThreadPool();
