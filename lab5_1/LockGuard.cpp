#include "LockGuard.h"

LockGuard::LockGuard(std::mutex& m) : m_(m){
    m_.lock();
}

LockGuard::LockGuard(LockGuard&& previous): m_(previous.m_){
    previous.m_ = std::mutex;
}

LockGuard::~LockGuard() {
    m_.unlock();
}

