#include <iostream>

#include "iter.hpp"

template <typename T>
void print(const T& num) {
    std::cout << num << " ";
}

int main() {
    size_t size = 5;

    // 예시 1) int 배열
    int int_arr[5] = {1, 2, 3, 4, 5};

    iter(int_arr, size, print<int>);
    std::cout << std::endl;

    // 예시 2) const char 배열
    const char char_arr[5] = {'a', 'b', 'c', 'd', 'e'};

    iter(char_arr, size, print<char>);
    std::cout << std::endl;

    return 0;
}