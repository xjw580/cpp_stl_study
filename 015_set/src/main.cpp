/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

void demo1() {
    // 声明一个整型 set 容器
    std::set<int, std::greater<int> > mySet;
    // std::set<int> mySet;

    // 插入元素
    mySet.insert(40);
    mySet.insert(10);
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);


    std::cout << "count 10: " << mySet.count(10) << std::endl;

    // 输出 set 中的元素
    std::cout << "Set contains: ";
    for (const int num: mySet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 查找元素
    // if (mySet.find(20) != mySet.end()) {
    if (mySet.contains(20)) {
        std::cout << "20 is in the set." << std::endl;
    } else {
        std::cout << "20 is not in the set." << std::endl;
    }

    // 删除元素
    // mySet.erase(20);

    // 再次输出 set 中的元素
    std::cout << "After erasing 20, set contains: ";
    for (const int num: mySet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 检查 set 是否为空
    if (mySet.empty()) {
        std::cout << "The set is empty." << std::endl;
    } else {
        std::cout << "The set is not empty." << std::endl;
    }

    // 输出 set 中元素的数量
    std::cout << "The set contains " << mySet.size() << " elements." << std::endl;

    int point_v = 30;

    auto upper_bound = mySet.upper_bound(point_v);
    std::cout << "upper_bound: " << *upper_bound << '\n';
    for (auto it = mySet.begin(); it != upper_bound; ++it) {
        std::cout << *it << " ";
    }

    std::cout << '\n';

    auto lower_bound = mySet.lower_bound(point_v);
    std::cout << "lower_bound: " << *lower_bound << '\n';

    for (auto it = mySet.begin(); it != lower_bound; ++it) {
        std::cout << *it << " ";
    }

}

void main() {
    demo1();
    std::cout.flush();
}
