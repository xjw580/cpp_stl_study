/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

using namespace std;

void demo1() {
    vector<string> myvt; // 定义模板类对象
    myvt.reserve(4); // 设置大小
    cout << "The size is 4." << endl;

    // 添加内容
    myvt.push_back("1. Beijing City.");
    myvt.push_back("2. Tianjin City.");
    myvt.push_back("3. Shanghai City.");
    myvt.push_back("4. Chongqing City.");

    // 打印内容
    vector<string>::iterator it;
    for (it = myvt.begin(); it != myvt.end(); it++) {
        cout << *it << endl;
    }

    int m = myvt.size(); // 获取大小
    int n = myvt.capacity(); // 获取容量
    int m1 = myvt.max_size(); // 获取最大大小
    cout << "vector:myvt, size is " << m << endl;
    cout << "vector:myvt, capacity is " << n << endl;
    cout << "vector:myvt, maxsize is " << m1 << endl;

    myvt.resize(10); //重设大小
    cout << "resize: 10." << endl;
    int n1 = myvt.capacity();
    int n2 = myvt.size();
    cout << "vector:myvt, capacity is " << n1 << endl;
    cout << "vector:myvt, size is " << n2 << endl;

    // 如果为空值则打印 * 号
    for (it = myvt.begin(); it != myvt.end(); it++) {
        if (*it == "")
            cout << "******" << endl;
        cout << *it << endl;
    }
}

void demo2() {
    // 按上述顺序使用的构造函数：
    std::vector<int> first; // 整数的空向量
    std::vector<int> second(4, 100); // 值为100的四个整数
    std::vector<int> third(second.begin(), second.end()); // 遍历构造
    std::vector<int> fourth(third); // 赋值构造

    // 迭代器构造函数也可用于从数组构造：
    int myints[] = {16, 2, 77, 29};
    std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

    std::cout << "The contents of fifth are:";
    for (auto it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
}

void demo3() {
    cout << "hello" << endl;
    std::vector<int> foo(3, 0); // foo: 0 0 0
    std::vector<int> bar(5, 0); // bar: 0 0 0 0 0

    bar = foo; // bar: 0 0 0
    foo = std::vector<int>(); // foo:

    std::cout << "Size of foo: " << int(foo.size()) << '\n';
    std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

void demo4() {
    std::vector<int> v{1};
    if (!v.empty()) {
        cout << "front:" << v.front() << endl;
        cout << "back:" << v.back() << endl;
    }
    cout << "demo4" << endl;
    cout << "begin: " << std::boolalpha << (v.begin() == v.end()) << endl;
}

void demo5() {
    std::vector<int> first;
    std::vector<int> second;
    std::vector<int> third;
    std::vector<int> fourth;

    first.assign(7, 100); // 7个整数，值为100

    std::vector<int>::iterator it;
    it = first.begin() + 1;

    second.assign(it, first.end() - 1); // 从第2个值到到数第1个值

    int myints[] = {1776, 7, 4};
    third.assign(myints, myints + 3); // 从数组分配

    fourth.assign({1, 2, 3, 4, 5});

    std::cout << "Size of first: " << int(first.size()) << '\n';
    std::cout << "Size of second: " << int(second.size()) << '\n';
    std::cout << "Size of third: " << int(third.size()) << '\n';
    std::cout << "Size of fourth: " << int(fourth.size()) << '\n';
}

void demo6() {
    std::vector<int> myvector(3, 100);
    std::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert(it, 200);

    myvector.insert(it, 2, 300);

    // "it" 不再有效，请换一个新的:
    it = myvector.begin();

    std::vector<int> anothervector(2, 400);
    myvector.insert(it + 2, anothervector.begin(), anothervector.end());

    int myarray[] = {501, 502, 503};
    myvector.insert(myvector.begin(), myarray, myarray + 3);

    std::cout << "myvector contains:";
    for (it = myvector.begin(); it < myvector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';
}


void main() {
    // demo1();
    // demo2();
    // demo3();
    // demo4();
    demo5();
    // demo6();
    std::cout.flush();
}
