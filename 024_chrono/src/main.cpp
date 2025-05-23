/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

// 打印当前时间
void unique_ptr_demo() {
    auto now = std::chrono::system_clock::now();
    std::cout << std::format("{:%Y-%m-%d %H:%M:%S}", now) << '\n';
    // std::cout << std::format("{:%y-%m-%d %H:%M:%S}", now) << '\n';
}

void shared_ptr_demo() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::cout << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");
}

void main() {
    unique_ptr_demo();
    std::cout.flush();
}
