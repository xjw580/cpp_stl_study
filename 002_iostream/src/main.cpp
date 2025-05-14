/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

/**
 * 格式化
 */
static void iomanip() {
    double pi = 3.14159;

    // 设置输出精度，持续生效，直到再次修改
    std::cout << std::setprecision(3) << pi << std::endl;
    std::cout << std::setprecision(6);
    // 设置输出宽度和对齐方式
    std::cout << std::setw(10) << std::left << pi << std::endl;
    std::cout << std::setw(10) << std::right << pi << std::endl;
    std::cout << std::setw(10) << std::right << "hello" << std::endl;
}

/**
 * 检查流的状态
 */
static void checkStatus() {
    int num;
    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> num;
        if (std::cin.fail()) {
            std::cout << "Invalid input" << std::endl;
            // 清除错误状态
            std::cin.clear();
            // 丢弃缓冲区中的错误输入（直到遇到换行符为止）
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cout << "Input: " << num << std::endl;
            // 清除错误状态
            std::cin.clear();
            // 丢弃缓冲区中的错误输入（直到遇到换行符为止）
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
}

static void input() {
    std::string input;
    std::cout << "Enter a string: ";
    auto &c = std::cin;
    std::getline(std::cin, input);
    std::cout << "string:" << input << std::endl;
    std::cout << "Enter a string: ";
    char input1[256];
    std::cin >> input1;
    std::cout << "string1:" << input1 << std::endl;
}

int main() {
    iomanip();
    checkStatus();
    input();
}
