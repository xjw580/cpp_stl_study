/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

void sort() {
    std::stack<int> s;

    // 向栈中添加元素
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "size: " << s.size() << std::endl;

    // 打印栈顶元素
    std::cout << "Top element is: " << s.top() << std::endl; // 输出: Top element is: 30

    // 移除栈顶元素
    s.pop();
    std::cout << "After popping, top element is: " << s.top() << std::endl; // 输出: After popping, top element is: 20

    // 检查栈是否为空
    if (!s.empty()) {
        std::cout << "Stack is not empty." << std::endl; // 输出: Stack is not empty.
    }

    // 打印栈的大小
    std::cout << "Size of stack: " << s.size() << std::endl; // 输出: Size of stack: 2

    // 继续移除元素
    s.pop();
    s.pop();

    // 检查栈是否为空
    if (s.empty()) {
        std::cout << "Stack is empty." << std::endl; // 输出: Stack is empty.
    }
}

void main() {
    sort();
    std::cout.flush();
}
