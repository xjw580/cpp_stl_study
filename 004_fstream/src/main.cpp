/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;
#include <sys/stat.h>

static void write() {
    std::fstream file;
    file.open("example.txt", std::ios::out); // 以输出模式打开文件

    if (!file) {
        std::cerr << "Unable to open file!" << std::endl;
        return; // 文件打开失败
    }

    file << "Hello, World!" << std::endl; // 写入文本
    file.close(); // 关闭文件
}

static void read() {
    std::fstream file;
    file.open("example.txt");
    if (!file) {
        std::cerr << "Unable to open file!" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

static void info() {
    std::filesystem::path filePath = "example.txt";

    try {
        if (std::filesystem::exists(filePath) && std::filesystem::is_regular_file(filePath)) {
            auto size = std::filesystem::file_size(filePath);
            std::cout << "文件大小: " << size << " 字节\n";
            // 获取文件的最后写入时间
            auto ftime = std::filesystem::last_write_time(filePath);

            // 将file_time_type转换为system_clock的time_point
            auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
                ftime - std::filesystem::file_time_type::clock::now() +
                std::chrono::system_clock::now());

            // 转换为time_t
            std::time_t tt = std::chrono::system_clock::to_time_t(sctp);

            // 转换为本地时间并格式化输出
            std::tm *local_tm = std::localtime(&tt);
            std::cout << "Last write time: "
                    << std::put_time(local_tm, "%Y-%m-%d %H:%M:%S")
                    << std::endl;
        } else {
            std::cout << "文件不存在或不是普通文件。\n";
        }
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "发生错误: " << e.what() << '\n';
    }
}

static void copy() {
    std::ifstream in;
    std::ofstream out;
    in.open(R"(C:\Users\28671\Documents\1.pdf)", std::ios::binary);
    if (!in) {
        std::cerr << "Unable to open file!" << std::endl;
        return;
    }
    out.open(R"(C:\Users\28671\Documents\1_copy.pdf)", std::ios::binary);
    if (!out) {
        std::cerr << "Unable to open file!" << std::endl;
        return;
    }
    char buffer[1024];
    while (in.read(buffer, sizeof(buffer))) {
        out.write(buffer, sizeof(buffer));
    }
    in.close();
    out.close();
    std::cout << "copy completed" << std::endl;
}

static void fastCopy() {
    const std::filesystem::path src = R"(C:\Users\28671\Documents\1.pdf)";
    const std::filesystem::path dst = R"(C:\Users\28671\Documents\1_fast_copy.pdf)";

    try {
        std::filesystem::copy_file(
            src, dst,
            std::filesystem::copy_options::overwrite_existing // 可选：允许覆盖
        );
        std::cout << "copy completed" << std::endl;
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "Copy failed: " << e.what() << std::endl;
    }
}


void fastCopyDirectory(const std::filesystem::path &src, const std::filesystem::path &dst) {
    try {
        std::filesystem::copy(
            src, dst,
            std::filesystem::copy_options::recursive |
            std::filesystem::copy_options::overwrite_existing
        );
        std::cout << "Directory copy completed." << std::endl;
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "Error copying directory: " << e.what() << std::endl;
    }
}

int main() {
    write();
    read();
    info();
    copy();
    fastCopy();
    // fastCopyDirectory(R"(C:\Users\28671\Documents\试用期)", R"(C:\Users\28671\Documents\试用期_copy)");
    return 0;
}
