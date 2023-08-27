/*
 * @Author: huomax 630509357@qq.com
 * @Date: 2023-08-05 21:58:30
 * @LastEditors: huomax 630509357@qq.com
 * @LastEditTime: 2023-08-27 21:11:29
 * @FilePath: /sylar-huomax/tests/test_thread.cc
 * @Description: 
 * 
 * Copyright (c) 2023 by huomax, All Rights Reserved. 
 */
#include "sylar/sylar.h"

sylar::Logger::ptr g_logger = SYLAR_LOG_ROOT();

int count = 0;
sylar::Mutex s_mutex;

void func1(void *arg) {
    SYLAR_LOG_INFO(g_logger) << "name:" << sylar::Thread::GetName()
        << " this.name:" << sylar::Thread::GetThis()->getName()
        << " thread name:" << sylar::GetThreadName()
        << " id:" << sylar::GetThreadId()
        << " this.id:" << sylar::Thread::GetThis()->getId();
    SYLAR_LOG_INFO(g_logger) << "arg: " << *(int*)arg;
    for(int i = 0; i < 10000; i++) {
        sylar::Mutex::Lock lock(s_mutex);
        ++count;
    }
}

int main(int argc, char *argv[]) {
    sylar::EnvMgr::GetInstance()->init(argc, argv);
    sylar::Config::LoadFromConfDir(sylar::EnvMgr::GetInstance()->getConfigPath());

    std::vector<sylar::Thread::ptr> thrs;
    int arg = 123456;
    for(int i = 0; i < 3; i++) {
        // 带参数的线程用std::bind进行参数绑定
        sylar::Thread::ptr thr(new sylar::Thread(std::bind(func1, &arg), "thread_" + std::to_string(i)));
        thrs.push_back(thr);
    }

    for(int i = 0; i < 3; i++) {
        thrs[i]->join();
    }
    
    SYLAR_LOG_INFO(g_logger) << "count = " << count;
    return 0;
}

