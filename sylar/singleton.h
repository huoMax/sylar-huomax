/*
 * @Author: huomax 630509357@qq.com
 * @Date: 2023-08-02 19:54:56
 * @LastEditors: huomax 630509357@qq.com
 * @LastEditTime: 2023-08-02 20:05:10
 * @FilePath: /sylar-huomax/sylar/singleto.h
 * @Description: 单例模式封装
 * 
 * Copyright (c) 2023 by huomax, All Rights Reserved. 
 */

#ifndef __SYLAR_SINGLETON_H__
#define __SYLAR_SINGLETON_H__

#include <memory>

namespace sylar {

namespace {

template<class T, class X, int N>
T& GetInstanceX() {
    static T v;
    return v;
}

template<class T, class X, int N>
std::shared_ptr<T> GetInstancePtr() {
    static std::shared_ptr<T> v(new T);
    return v;
}
}

/**
 * @brief 单例模式封装类
 * @details T 类型
 *          X 为了创造多个实例对应的Tag
 *          N 同一个Tag创造多个实例索引
 */
template<class T, class X = void, int N = 0>
class Singleton {
public:
    /**
     * @brief 返回单例裸指针
     */
    static T* GetInstance() {
        static T v;
        return &v;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
private:
    Singleton();
};

/**
 * @brief 单例模式智能指针封装类
 * @details T 类型
 *          X 为了创造多个实例对应的Tag
 *          N 同一个Tag创造多个实例索引
 */
template<class T, class X = void, int N = 0>
class SingletonPtr {
public:
    /**
     * @brief 返回单例智能指针
     */
    static std::shared_ptr<T> GetInstance() {
        static std::shared_ptr<T> v(new T);
        return v;
    }

    SingletonPtr(const SingletonPtr&) = delete;
    SingletonPtr& operator=(const SingletonPtr&) = delete;
private:
    SingletonPtr();
};

}

#endif
