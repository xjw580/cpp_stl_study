

/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

void sort() {
    // 创建一个 map 容器，存储员工的姓名和年龄
    std::map<std::string, int, std::greater<std::string> > employees;

    // 插入员工信息
    employees["Alice"] = 30;
    employees["Bob"] = 25;
    employees["Charlie"] = 35;

    // 遍历 map 并打印员工信息
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        std::cout << it->first << " is " << it->second << " years old." << std::endl;
    }

    if (!employees.contains("hello")) {
        std::cout << "does not exist key hello" << std::endl;
    }
}

class Student {
public:
    int id;
    int age;
    std::string name;

    Student(int id, int age, std::string name)
        : id(id),
          age(age),
          name(std::move(name)) {
    }

    bool operator==(const Student &student) const {
        return id == student.id;
    }

    friend std::ostream &operator<<(std::ostream &os, const Student &s);
};

std::ostream &operator<<(std::ostream &os, const Student &s) {
    // 使用 {{ 和 }} 转义
    os << std::format("Student{{id: {}, age: {}, name: {}}}", s.id, s.age, 1);
    return os;
}

template<>
struct std::hash<Student> {
    size_t operator()(const Student &p) const noexcept {
        return hash<int>()(p.id);
    }
};

void shared_ptr_demo() {
    Student student1{112, 18, "zerg"};
    Student student2{112, 19, "queen"};
    std::hash<Student> hasher;
    std::cout << hasher(student1) << std::endl;
    std::cout << hasher(student2) << std::endl;
}


void demo3() {
    std::unordered_map<Student, int> map;
    Student student1 = Student{112, 18, "zerg"};
    Student student2 = Student{100, 19, "xjw"};
    map[student1] = 118;
    map[Student{112, 20, "queen"}] = 200;
    map[student2] = 110;
    std::cout << "size:" << map.size() << std::endl;
    if (map.contains(student1)) {
        std::cout << "student1: k=" << student1 << ",v=" << map[student1] << '\n';
    }
    if (map.contains(student2)) {
        std::cout << "student2: k=" << student1 << ",v=" << map[student2] << '\n';
    }
}

void main() {
    // demo1();
    // demo2();
    demo3();
    std::cout.flush();
}
