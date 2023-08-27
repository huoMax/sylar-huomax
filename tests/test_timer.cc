/*
 * @Author: huomax 630509357@qq.com
 * @Date: 2023-08-05 21:58:30
 * @LastEditors: huomax 630509357@qq.com
 * @LastEditTime: 2023-08-27 21:11:49
 * @FilePath: /sylar-huomax/tests/test_timer.cc
 * @Description: 
 * 
 * Copyright (c) 2023 by huomax, All Rights Reserved. 
 */
#include "sylar/sylar.h"

static sylar::Logger::ptr g_logger = SYLAR_LOG_ROOT();

static int timeout = 1000;
static sylar::Timer::ptr s_timer;

void timer_callback() {
    SYLAR_LOG_INFO(g_logger) << "timer callback, timeout = " << timeout;
    timeout += 1000;
    if(timeout < 5000) {
        s_timer->reset(timeout, true);
    } else {
        s_timer->cancel();
    }
}

void test_timer() {
    sylar::IOManager iom;

    // 循环定时器
    s_timer = iom.addTimer(1000, timer_callback, true);
    
    // 单次定时器
    iom.addTimer(500, []{
        SYLAR_LOG_INFO(g_logger) << "500ms timeout";
    });
    iom.addTimer(5000, []{
        SYLAR_LOG_INFO(g_logger) << "5000ms timeout";
    });
}

int main(int argc, char *argv[]) {
    sylar::EnvMgr::GetInstance()->init(argc, argv);
    sylar::Config::LoadFromConfDir(sylar::EnvMgr::GetInstance()->getConfigPath());

    test_timer();

    SYLAR_LOG_INFO(g_logger) << "end";

    return 0;
}