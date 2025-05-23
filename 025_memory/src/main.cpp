/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

class Student {
public:
    std::string name;

    Student(std::string name): name(std::move(name)) {
        std::cout << "constructor name: " << this->name << std::endl;
    }

    ~Student() {
        std::cout << "destructor name: " << name << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const Student &student);
};

std::ostream &operator<<(std::ostream &os, const Student &student) {
    os << "name: " << student.name;
    return os;
}

void unique_ptr_demo() {
    auto stu = std::make_unique<Student>("zerg");
}

void print_student(const std::shared_ptr<Student> stu) {
    std::cout << "use count: " << stu.use_count() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "use count: " << stu.use_count() << std::endl;
    std::cout << *stu.get() << std::endl;
}

void shared_ptr_demo() {
    const auto stu = std::make_shared<Student>("zerg");
    std::thread t1(print_student, stu);
    t1.detach();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}


struct B; // 前置声明

struct A {
    std::shared_ptr<B> ptrB;
    ~A() { std::cout << "A 析构\n"; }
};

struct B {
    std::weak_ptr<A> ptrA;  // 用weak_ptr打破循环引用
    ~B() { std::cout << "B 析构\n"; }
};

void weak_ptr_demo() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->ptrB = b;
    b->ptrA = a;  // weak_ptr 不增加引用计数

    std::cout << "a use_count: " << a.use_count() << std::endl; // 1
    std::cout << "b use_count: " << b.use_count() << std::endl; // 1
}

void main() {
    // unique_ptr_demo();
    // shared_ptr_demo();
    weak_ptr_demo();

    std::cout << "over" << '\n';
    std::cout.flush();
    std::cin.get();
}
