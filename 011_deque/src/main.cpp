/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

void demo1() {
    std::deque<int> myDeque;

    // 插入元素
    myDeque.push_back(10);
    myDeque.push_back(20);
    myDeque.push_front(5);

    // 访问元素
    std::cout << "Deque contains: ";
    for (int i = 0; i < myDeque.size(); ++i) {
        std::cout << myDeque[i] << " ";
    }
    std::cout << std::endl;

    // 删除元素
    myDeque.pop_back();
    myDeque.pop_front();

    // 再次访问元素
    std::cout << "Deque after popping: ";
    for (int i = 0; i < myDeque.size(); ++i) {
        std::cout << myDeque[i] << " ";
    }
    std::cout << std::endl;
}

void demo2() {
    std::deque<int> d;

    // 向双端队列中添加元素
    d.push_back(10);
    d.push_back(20);
    d.push_front(5);

    // 访问前端元素
    std::cout << "Front element: " << d.front() << std::endl;

    // 访问后端元素
    std::cout << "Back element: " << d.back() << std::endl;

    // 修改前端元素
    d.front() = 15;

    // 修改后端元素
    d.back() = 25;

    // 再次访问元素
    std::cout << "Modified front element: " << d.front() << std::endl;
    std::cout << "Modified back element: " << d.back() << std::endl;
}

void main() {
    // demo1();
    demo2();
    std::cout.flush();
}
