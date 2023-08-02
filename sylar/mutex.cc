/*
 * @Author: huomax 630509357@qq.com
 * @Date: 2023-08-02 19:55:17
 * @LastEditors: huomax 630509357@qq.com
 * @LastEditTime: 2023-08-02 20:20:30
 * @FilePath: /sylar-huomax/sylar/mutex.cc
 * @Description: 锁、信号量实现
 * 
 * Copyright (c) 2023 by huomax, All Rights Reserved. 
 */
#include "mutex.h"

namespace sylar {

Semaphore::Semaphore(uint32_t count) {
    if(sem_init(&m_semaphore, 0, count)) {
        throw std::logic_error("sem_init error");
    }
}

Semaphore::~Semaphore() {
    sem_destroy(&m_semaphore);
}

void Semaphore::wait() {
    if(sem_wait(&m_semaphore)) {
        throw std::logic_error("sem_wait error");
    }
}

void Semaphore::notify() {
    if(sem_post(&m_semaphore)) {
        throw std::logic_error("sem_post error");
    }
}

} // namespace sylar
