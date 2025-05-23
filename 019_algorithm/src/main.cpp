/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:

**************************************************************************/

import std;

namespace s_ranges = std::ranges;

void sort() {
    std::vector<int> numbers = {5, 2, 9, 1, 5, 6};
    std::ranges::sort(numbers, std::greater<int>());

    for (int num: numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void find() {
    std::vector numbers = {5, 1, 2, 2, 3, 4, 3};
    auto it = s_ranges::find(numbers, 2);
    if (it != numbers.end()) {
        auto index = it - numbers.begin();
        std::cout << "Found: " << *it << " in index " << index << std::endl;
    } else {
        std::cout << "Value not found." << std::endl;
    }

    s_ranges::sort(numbers);
    bool binary_search = s_ranges::binary_search(numbers, 0);
    std::cout << "binary_search 0: " << std::boolalpha << binary_search << std::endl;
    auto find_if = s_ranges::find_if(numbers, [](int x) { return x > 3; });

    if (find_if != numbers.end()) {
        std::cout << "find_if:" << find_if - numbers.begin() << std::endl;
    } else {
        std::cout << "Value not found." << std::endl;
    }
}

void copy() {
    std::vector<int> source = {1, 2, 3, 4, 5};
    int destination[5];
    s_ranges::copy(source, destination);

    for (int i: destination) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<int> dest2;
    // 或者使用resize，可直接传递begin
    dest2.reserve(source.size());
    s_ranges::copy(source, std::back_inserter(dest2));
    for (const int &value: dest2) {
        std::cout << value << " ";
    }
}

void equal() {
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2 = {1, 2, 3, 4, 5, 6};

    bool are_equal = s_ranges::equal(v1, v2);
    std::cout << (are_equal ? "Vectors are equal." : "Vectors are not equal.") << std::endl;
}

void modify() {
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::cout << "raw v1..." << std::endl;
    for (const int &value: v1) std::cout << value << "    ";
    std::cout << std::endl;

    s_ranges::reverse(v1);
    std::cout << "reverse v1..." << std::endl;
    for (const int &value: v1) std::cout << value << "    ";
    std::cout << std::endl;

    s_ranges::fill(v1, 2);
    std::cout << "fill v1..." << std::endl;
    for (const int &value: v1) std::cout << value << "    ";
    std::cout << std::endl;

    s_ranges::replace(v1, 2, 200);
    std::cout << "replace v1..." << std::endl;
    for (const int &value: v1) std::cout << value << "    ";
    std::cout << std::endl;
}

void permutation() {
    std::vector<int> v = {1, 2, 3};

    do {
        for (const int x: v) std::cout << x << " ";
        std::cout << std::endl;
    } while (s_ranges::next_permutation(v).found);

    std::cout << "===============\n";

    do {
        for (const int x: v) std::cout << x << " ";
        std::cout << std::endl;
    } while (s_ranges::prev_permutation(v).found);
}

void merge() {
    std::vector<int> vec1 = {1, 3, 5};
    std::vector<int> vec2 = {2, 4, 6};
    std::vector<int> result(vec1.size() + vec2.size());
    s_ranges::merge(vec1, vec2, result.begin());
    for (const int &value: result) {
        std::cout << value << " ";
    }
}

void other() {
    std::vector vec = {"1", "2", "3", "4", "5"};
    auto for_each = std::for_each(vec.begin(), vec.end(), [](int& x) { x += 1; });
}

void main() {
    // sort();
    // find();
    // copy();
    // equal();
    // modify();
    // permutation();
    merge();
    std::cout.flush();
}
