/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

void demo1() {
    // 创建一个整数类型的 unordered_set
    std::unordered_set<int> uset;

    // 插入元素
    uset.insert(30);
    uset.insert(20);
    uset.insert(10);
    uset.insert(20);

    // 打印 unordered_set 中的元素
    std::cout << "Elements in uset: ";
    for (int elem: uset) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 查找元素
    auto it = uset.find(20);
    if (it != uset.end()) {
        std::cout << "Element 20 found in uset." << std::endl;
    } else {
        std::cout << "Element 20 not found in uset." << std::endl;
    }

    // 删除元素
    uset.erase(20);
    std::cout << "After erasing 20, elements in uset: ";
    for (int elem: uset) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 检查大小和是否为空
    std::cout << "Size of uset: " << uset.size() << std::endl;
    std::cout << "Is uset empty? " << (uset.empty() ? "Yes" : "No") << std::endl;

    // 清空 unordered_set
    uset.clear();
    std::cout << "After clearing, is uset empty? " << (uset.empty() ? "Yes" : "No") << std::endl;
}

void demo2() {
    std::unordered_set<int> uset{1, 2, 3, 4, 5, 6, 6, 7, 8, 9, 10, 10};
    size_t bucket = uset.bucket(1);
    std::cout << "pos: " << bucket << std::endl;
    std::cout << "bucket count: " << uset.bucket_count() << std::endl;
    // 计算哈希
    std::cout << "hash func: " << uset.hash_function()(1) << std::endl;
    // 判断是否相等
    std::cout << "key equal: " << std::boolalpha << uset.key_eq()(1, 1) << std::endl;
    std::cout << "load_factor: " << uset.load_factor() << std::endl;
    std::cout << "max_bucket_count: " << uset.max_bucket_count() << std::endl;
    std::cout << "max_load_factor: " << uset.max_load_factor() << std::endl;
    uset.max_load_factor(10);
    std::cout << "set max_load_factor: " << uset.max_load_factor() << std::endl;
    std::cout << "max_size: " << uset.max_size() << std::endl;
    std::cout << "bucket_size:" << uset.bucket_size(bucket) << std::endl;
}

void main() {
    // demo1();
    demo2();
    std::cout.flush();
}
