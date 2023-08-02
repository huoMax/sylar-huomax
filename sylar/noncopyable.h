/*
 * @Author: huomax 630509357@qq.com
 * @Date: 2023-08-02 20:06:45
 * @LastEditors: huomax 630509357@qq.com
 * @LastEditTime: 2023-08-02 20:07:00
 * @FilePath: /sylar-huomax/sylar/noncopyable.h
 * @Description: 不可拷贝类封装
 * 
 * Copyright (c) 2023 by huomax, All Rights Reserved. 
 */
#ifndef __SYLAR_NONCOPYABLE_H__
#define __SYLAR_NONCOPYABLE_H__

namespace sylar {

/**
 * @brief 对象无法拷贝,赋值
 */
class Noncopyable {
public:
    /**
     * @brief 默认构造函数
     */
    Noncopyable() = default;

    /**
     * @brief 默认析构函数
     */
    ~Noncopyable() = default;

    /**
     * @brief 拷贝构造函数(禁用)
     */
    Noncopyable(const Noncopyable&) = delete;

    /**
     * @brief 赋值函数(禁用)
     */
    Noncopyable& operator=(const Noncopyable&) = delete;
};

}

#endif
