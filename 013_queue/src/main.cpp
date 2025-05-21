/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

void demo1() {
    // 创建一个整数队列
    std::queue<int> q;

    // 向队列中添加元素
    q.push(10);
    q.push(20);
    q.push(30);

    // 打印队列中的元素数量
    std::cout << "size: " << q.size() << std::endl;

    // 打印队首元素
    std::cout << "front: " << q.front() << std::endl;

    // 打印队尾元素
    std::cout << "back: " << q.back() << std::endl;

    // 移除队首元素
    q.pop();
    std::cout << "after pop front: " << q.front() << std::endl;

    // 再次打印队列中的元素数量
    std::cout << "size: " << q.size() << std::endl;
}

void main() {
    demo1();
    std::cout.flush();
}
