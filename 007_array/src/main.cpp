/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

struct Student {
    std::string name;
    int age;
};

template<typename... Args>
void countArgs(Args... args) {
    std::cout << sizeof...(Args) << '\n';
    (std::cout << ... << args) << '\n';
}

int main() {
    int ints[10] = {0};
    countArgs(); // 输出 0
    countArgs(1); // 输出 1
    countArgs(1, 2, 3, 4);
    std::array array = {Student{"", 18}};
    array.fill({"zerg", 18});
    array.at(0).age = 30;
    std::to_array()
    auto &student = array.at(0);
    student.age = 20;
    for (auto array_iterator = array.begin(); array_iterator != array.end(); ++array_iterator) {
    }
    for (const auto &[name, age]: array) {
        std::cout << "name:" << name << ", age:" << age << std::endl;
    }
    char i1 = -127;
    unsigned char i2 = i1;
    std::cout << "i2:" << (int)i2 << std::endl;
    int i = std::numeric_limits<int>::min() + 100;
    std::cout << "i:" << i << std::endl;
    unsigned __int64 ii = i;
    std::cout << "ii:" << ii << std::endl;
    return 0;
}
