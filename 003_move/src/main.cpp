/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;


class MyClass {
public:
    MyClass() {
        std::cout << "Default Constructor\n";
    }

    MyClass(const MyClass&) {
        std::cout << "Copy Constructor\n";
    }

    MyClass(MyClass&&) noexcept {
        std::cout << "Move Constructor\n";
    }

    ~MyClass() {
        std::cout << "Destructor\n";
    }
};

// 值传递：会触发拷贝或移动构造
void passByValue(MyClass obj) {
    std::cout << "Inside passByValue\n";
}

// 右值引用：不触发构造函数，只绑定引用
void passByRValueRef(MyClass&& obj) {
    std::cout << "Inside passByRValueRef\n";
}

// 常量引用：也不触发构造函数
void passByConstRef(const MyClass& obj) {
    std::cout << "Inside passByConstRef\n";
}

MyClass get() {
    MyClass obj;
    return obj;
}

int main() {
    MyClass obj = get();
    // std::cout << "--- Creating object a ---\n";
    // MyClass a;
    //
    // std::cout << "\n--- Call: passByValue(a) ---\n";
    // passByValue(a);  // 拷贝构造
    //
    // std::cout << "\n--- Call: passByValue(std::move(a)) ---\n";
    // passByValue(std::move(a));  // 移动构造
    //
    // std::cout << "\n--- Call: passByRValueRef(std::move(a)) ---\n";
    // passByRValueRef(std::move(a));  // 右值引用绑定，不构造
    //
    // std::cout << "\n--- Call: passByConstRef(a) ---\n";
    // passByConstRef(a);  // const 引用绑定，不构造
    //
    // std::cout << "\n--- End of main ---\n";
    return 0;
}

