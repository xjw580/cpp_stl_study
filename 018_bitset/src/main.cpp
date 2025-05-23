

/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

void sort() {
    std::bitset<8> b("11001010"); // 从字符串初始化
    // std::bitset<8> b(127); // 从字符串初始化
    std::cout << "Initial bitset: " << b << std::endl;

    // 访问特定位置的位
    std::cout << "Bit at position 3: " << b[3] << std::endl;

    // 修改位
    b[2] = 1;
    std::cout << "Modified bitset: " << b << std::endl;

    // 翻转位
    b.flip();
    std::cout << "Flipped bitset: " << b << std::endl;
}

void shared_ptr_demo() {
    std::bitset<8> b1("10101010");
    std::bitset<8> b2("11110000");

    // 位与操作
    std::bitset<8> b_and = b1 & b2;
    std::cout << "Bitwise AND: " << b_and << std::endl;

    // 位或操作
    std::bitset<8> b_or = b1 | b2;
    std::cout << "Bitwise OR: " << b_or << std::endl;

    // 位异或操作
    std::bitset<8> b_xor = b1 ^ b2;
    std::cout << "Bitwise XOR: " << b_xor << std::endl;

    // 位非操作
    std::bitset<8> b_not = ~b1;
    std::cout << "Bitwise NOT: " << b_not << std::endl;
}

void demo3() {
    std::bitset<8> b("10101010");

    // 循环遍历bitset中的位
    for (size_t i = 0; i < b.size(); ++i) {
        std::cout << b[i];
    }
    std::cout << std::endl;
}

void main() {
    // demo1();
    // demo2();
    demo3();
    std::cout.flush();
}
