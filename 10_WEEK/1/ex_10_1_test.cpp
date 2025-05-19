
#include <iostream>
#include <vector>
#include "ex_10_1_a.cpp"
#include "ex_10_1_b.cpp"

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};

    std::cout << std::boolalpha;
    std::cout << "hasSize<int>: " << hasSize<int>::value << "\n"; // false
    std::cout << "hasSize<vector<int>>: " << hasSize<std::vector<int> >::value << "\n"; // true

    std::cout << "hasValueType<int>: " << hasValueType<int>::value << "\n"; // false
    std::cout << "hasValueType<vector<int>>: " << hasValueType<std::vector<int> >::value << "\n"; // true

    std::cout << "v1::getSize(5): " << v1::getSize(5) << "\n"; // 4 (sizeof(int))
    std::cout << "v1::getSize(v): " << v1::getSize(v) << "\n"; // 20 (5 * 4)

    std::cout << "v2::getSize(5): " << v2::getSize(5) << "\n"; // 4
    std::cout << "v2::getSize(v): " << v2::getSize(v) << "\n"; // 20
}
