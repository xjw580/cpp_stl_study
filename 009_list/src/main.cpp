
/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

class String {
public:
    String(const char *str) {
        std::cout << "constructor" << std::endl;
    }

    String(const String &other) {
        std::cout << "copy constructor" << std::endl;
    }

    String(String &&other) noexcept {
        std::cout << "move constructor" << std::endl;
    }

    String &operator=(const String &other) {
        std::cout << "copy assignment" << std::endl;
        if (this == &other)
            return *this;
        return *this;
    }

    String &operator=(String &&other) noexcept {
        std::cout << "move assignment" << std::endl;
        if (this == &other)
            return *this;
        return *this;
    }
};

class Student {
public:
    int age;
    String name;

    Student(const int age, String name)
        : age(age),
          name(std::move(name)) {
    }

    // Student(const int age, String &&name)
    //     : age(age),
    //       name(std::move(name)) {
    // }

    bool operator<(const Student &other) const {
        return age < other.age;
    }

    bool operator==(const Student &other) const {
        return other.age == age;
    }
};

void sort() {
    // 创建一个整数类型的列表
    std::list<int> numbers;

    // 向列表中添加元素
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);

    // 访问并打印列表的第一个元素
    std::cout << "First element: " << numbers.front() << std::endl;

    // 访问并打印列表的最后一个元素
    std::cout << "Last element: " << numbers.back() << std::endl;

    // 遍历列表并打印所有元素
    std::cout << "List elements: ";
    for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "size: " << numbers.size() << std::endl;
    std::cout << std::endl;

    // 删除列表中的最后一个元素
    numbers.pop_back();

    // 再次遍历列表并打印所有元素
    std::cout << "List elements after removing the last element: ";
    for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << '\n';
    // 访问索引为2的元素
    auto begin = numbers.begin();
    std::advance(begin, 2);
    std::cout << "index 2: " << *begin << '\n';
    std::cout << std::endl;
}

void shared_ptr_demo() {
    std::list<Student> student_list{Student{9, ""}, Student{18, ""}, Student{11, ""}, Student{10, ""}, Student{10, ""}};
    std::cout << std::setw(15) << std::left << std::setfill('=') << "raw" << "\n";
    for (const auto &list: student_list) {
        std::cout << list.age << std::endl;
    }
    student_list.sort();
    std::cout << std::setw(15) << std::left << std::setfill('=') << "sort" << "\n";
    for (const auto &list: student_list) {
        std::cout << list.age << std::endl;
    }
    student_list.unique();
    std::cout << std::setw(15) << std::left << std::setfill('=') << "unique" << "\n";
    for (const auto &list: student_list) {
        std::cout << list.age << std::endl;
    }
}

void main() {
    sort();
    // Student student1{18, String("df")};
    // demo2();
    std::cout.flush();
}
