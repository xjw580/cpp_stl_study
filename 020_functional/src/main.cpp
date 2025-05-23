/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

void greet() {
    std::cout << "Hello, World!" << std::endl;
}

void unique_ptr_demo() {
    std::function f = greet; // 使用函数
    f(); // 输出: Hello, World!

    std::function lambda = [] {
        std::cout << "Hello, Lambda!" << std::endl;
    };
    lambda(); // 输出: Hello, Lambda!
}

int add(int a, int b) {
    return a + b;
}

void shared_ptr_demo() {
    auto bound_add = std::bind(add, 5, std::placeholders::_1);
    std::cout << bound_add(10) << std::endl; // 输出: 15
}

void main() {
    // demo1();
    shared_ptr_demo();
    std::cout.flush();
}
