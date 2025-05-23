/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

// cpp17已被收入标准库
#include <boost/filesystem.hpp>
import std;
namespace fs = boost::filesystem;
// namespace fs = std::filesystem;

// 路径拼接、解析
void sort() {
    fs::path p1("S:/test");
    fs::path p2("data.txt");
    fs::path full = p1 / p2;
    std::cout << "Full path: " << full.string() << '\n';
}

// 创建目录 / 删除目录
void shared_ptr_demo() {
    fs::create_directory("output");
    fs::remove("output");
}

// 遍历
void demo3(const fs::path &path) {
    if (fs::is_directory(path)) {
        std::cout << std::setw(6) << std::left << "dir:" << path.string() << '\n';
        for (auto &entry: fs::directory_iterator(path)) {
            demo3(entry.path());
        }
    } else {
        std::cout << std::setw(6) << std::left << "file:" << path.string() << '\n';
    }
}

void main() {
    // demo1();
    // demo2();
    demo3(fs::current_path());
    std::cout.flush();
}
