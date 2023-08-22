#include <iostream>

#include "iter.hpp"

template <typename T>
void printNum(const T& num) {
    std::cout << num << " ";
}

int main() {
    size_t size = 5;

    // 예시 1) int 배열
    int int_arr[size];
    for (size_t i = 0; i < size; i++)
        int_arr[i] = i;

    iter(int_arr, size, printNum<int>);
    std::cout << std::endl;

    // 예시 2) char 배열
    char char_arr[size];
    for (size_t i = 0; i < size; i++)
        char_arr[i] = static_cast<char>('a' + i);

    iter(char_arr, size, printNum<char>);
    std::cout << std::endl;

    return 0;
}