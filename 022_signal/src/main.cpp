/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:https://www.runoob.com/cplusplus/cpp-signal-handling.html

**************************************************************************/

import std;
#include <csignal>

[[noreturn]] void unique_ptr_demo() {
    // 注册信号 SIGINT 和信号处理程序，按 Ctrl+C 来中断程序
    std::signal(SIGINT, [](int signum) {
        std::cout << "Interrupt signal (" << signum << ") received.\n";
        std::exit(signum);
    });

    while (true) {
        std::cout << "Going to sleep...." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void main() {
    unique_ptr_demo();
    std::cout.flush();
}
