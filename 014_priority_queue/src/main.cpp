/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

struct compare {
    bool operator()(int a, int b) {
        return a > b; // 定义最小堆
    }
};


void sort() {
    // 创建一个自定义类型的优先队列，使用最小堆
    std::priority_queue<int, std::vector<int>, decltype([](const int &lhs, const int &rhs) { return lhs > rhs; })> pq_min;
    // std::priority_queue<int, std::vector<int>, std::greater<int>> pq_min;
    // std::priority_queue<int, std::vector<int>, compare> pq_min;


    // 向优先队列中添加元素
    pq_min.push(30);
    pq_min.push(10);
    pq_min.push(50);
    pq_min.push(20);

    // 输出队列中的元素
    std::cout << "min heap:" << std::endl;
    while (!pq_min.empty()) {
        std::cout << pq_min.top() << std::endl;
        pq_min.pop();
    }
}

void main() {
    sort();
    std::cout.flush();
}
