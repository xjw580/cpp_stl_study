/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;
import test;

int main()
{
    test::hello();
    std::cout << "Import the STL library for best performance\n";
    std::vector<int> v{5, 5, 5};
    for (const auto& e : v)
    {
        std::cout << e;
    }
}