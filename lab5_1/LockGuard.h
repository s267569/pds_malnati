//
// Created by Domenico Cefalo on 30/05/21.
//

#ifndef LAB5_1_LOCKGUARD_H
#define LAB5_1_LOCKGUARD_H

#include <mutex>

class LockGuard{
    std::mutex& m_;

public:
    explicit LockGuard(std::mutex& m);
    ~LockGuard();
};

#endif //LAB5_1_LOCKGUARD_H
