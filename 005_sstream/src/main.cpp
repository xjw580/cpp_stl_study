/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description: 处理字符串流

**************************************************************************/

import std;

static void isstream() {
    std::cout << "=======================isstream=======================" << std::endl;
    std::istringstream is("hello world 123 12.3");
    char one[256], two[256];
    int numi;
    double numd;
    is >> one >> two >> numi >> numd;
    std::cout << "one: " << one << "\n"
            << "two: " << two << "\n"
            << "num: " << numi << "\n"
            << "numd: " << numd << std::endl;
}

static void osstream() {
    std::cout << "=======================osstream=======================" << std::endl;
    std::ostringstream os;
    os << "hello cpp" << ", hello world\n";
    std::cout << "out: " << os.str() << std::endl;
}

static void sstream() {
    std::cout << "=======================sstream=======================" << std::endl;
    std::stringstream ss;
    ss << "hello stl";
    std::cout << "out: " << ss.str() << std::endl;
    char one[256], two[256];
    ss >> one >> two;
    std::cout << "one: " << one << "\n"
            << "two: " << two << std::endl;
}

int main() {
    isstream();
    osstream();
    sstream();
    return 0;
}
