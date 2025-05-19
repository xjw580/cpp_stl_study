/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description: 对输入/输出流的格式化操作
https://www.runoob.com/cplusplus/cpp-libs-iomanip.html

| 操作器                         | 说明                                       | 示例代码                                              | 输出     |
|------------------------------|------------------------------------------|------------------------------------------------------|----------|
| `std::setw(int n)`           | 设置字段宽度，为下一次输出指定宽度                   | `std::cout << std::setw(5) << 42;`                   | `   42`  |
| `std::setfill(char)`         | 设置填充字符（默认是空格）                        | `std::cout << std::setfill('*') << std::setw(5) << 42;` | `**42`   |
| `std::left`                  | 设置左对齐                                 | `std::cout << std::left << std::setw(5) << 42;`      | `42   `  |
| `std::right`                 | 设置右对齐（默认）                            | `std::cout << std::right << std::setw(5) << 42;`     | `   42`  |
| `std::internal`              | 符号靠左，其余靠右                             | `std::cout << std::internal << std::setw(5) << -42;` | `-  42`  |
| `std::setprecision(int)`     | 设置浮点数的有效位数                           | `std::cout << std::setprecision(3) << 3.14159;`      | `3.14`   |
| `std::fixed`                 | 设置定点格式输出浮点数                           | `std::cout << std::fixed << std::setprecision(2) << 3.14159;` | `3.14`   |
| `std::scientific`            | 设置科学计数法格式输出浮点数                       | `std::cout << std::scientific << 3.14159;`           | `3.141590e+00` |
| `std::hex`                   | 设置整数以 16 进制显示                          | `std::cout << std::hex << 42;`                       | `2a`     |
| `std::oct`                   | 设置整数以 8 进制显示                           | `std::cout << std::oct << 42;`                       | `52`     |
| `std::dec`                   | 设置整数以 10 进制显示（默认）                   | `std::cout << std::dec << 42;`                       | `42`     |
| `std::showbase`             | 显示进制前缀（如 0x 表示 16 进制）              | `std::cout << std::showbase << std::hex << 42;`      | `0x2a`   |
| `std::noshowbase`           | 隐藏进制前缀（默认）                            | `std::cout << std::noshowbase << std::hex << 42;`    | `2a`     |
| `std::uppercase`            | 16 进制字母显示为大写                          | `std::cout << std::uppercase << std::hex << 42;`     | `2A`     |
| `std::nouppercase`          | 16 进制字母显示为小写（默认）                    | `std::cout << std::nouppercase << std::hex << 42;`   | `2a`     |
| `std::showpos`              | 正数前显示 `+` 符号                            | `std::cout << std::showpos << 42;`                   | `+42`    |
| `std::noshowpos`            | 不显示正数符号（默认）                          | `std::cout << std::noshowpos << 42;`                 | `42`     |
| `std::boolalpha`            | 布尔值以 `true/false` 输出                     | `std::cout << std::boolalpha << true;`               | `true`   |
| `std::noboolalpha`          | 布尔值以 `1/0` 输出（默认）                     | `std::cout << std::noboolalpha << true;`             | `1`      |
| `std::setbase(int n)`       | 设置整数的进制（支持 8, 10, 16）                 | `std::cout << std::setbase(16) << 42;`               | `2a`     |
| `std::resetiosflags(flags)` | 重置指定的流状态                               | `std::cout << std::resetiosflags(std::ios::showbase) << std::hex << 42;` | `2a` |
| `std::setiosflags(flags)`   | 设置指定的流状态                               | `std::cout << std::setiosflags(std::ios::showbase) << std::hex << 42;`   | `0x2a` |


**************************************************************************/

import std;

int main() {
    std::cout << std::boolalpha << true << std::endl;

    double pi = 3.14159;

    std::cout << std::setiosflags(std::ios::fixed);
    std::cout << std::setprecision(2) << pi << std::endl;  // 输出：3.14

    // std::cout << std::resetiosflags(std::ios::fixed);      // 清除 fixed
    // std::cout << std::setiosflags(std::ios::scientific);
    std::cout << std::scientific << 3.141592653589793 << std::endl;
    // std::cout << std::setprecision(2) << pi << std::endl;  // 输出：3.14e+00
    std::cout << std::setprecision(2) << pi << std::endl;  // 输出：3.14e+00
    return 0;
}
