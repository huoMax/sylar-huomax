/*
 * @Author: huomax 630509357@qq.com
 * @Date: 2023-08-27 21:02:16
 * @LastEditors: huomax 630509357@qq.com
 * @LastEditTime: 2023-08-27 21:11:55
 * @FilePath: /sylar-huomax/tests/test_uri.cc
 * @Description: 
 * 
 * Copyright (c) 2023 by huomax, All Rights Reserved. 
 */
#include "sylar/sylar.h"
#include <iostream>

int main(int argc, char * argv[]) {
    auto uri = sylar::Uri::Create("http://a:b@host.com:8080/p/a/t/h?query=string#hash");
    std::cout << uri->toString() << std::endl;
    return 0;
}