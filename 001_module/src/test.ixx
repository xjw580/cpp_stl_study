/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:58

Description:

**************************************************************************/

module;
import std;
export module test;

export
{
    namespace test {
        void hello();
    }

}

void test::hello() {
    std::cout << "hello" << std::endl;
};
