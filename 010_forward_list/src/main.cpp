/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

void demo1() {
    std::forward_list l1{1, 2, 3, 4, 5};
    std::cout << "front: " << l1.front() << std::endl;

    auto begin = l1.begin();
    l1.erase_after(std::next(begin, 2));
    auto size = std::distance(begin, l1.end());
    std::advance(begin, size - 1);
    std::cout << "back: " << *begin << std::endl;
    std::cout << "size: " << size << std::endl;
    for (const int &value: l1)
        std::cout << value << std::endl;
}

void main() {
    demo1();
    std::cout.flush();
}
