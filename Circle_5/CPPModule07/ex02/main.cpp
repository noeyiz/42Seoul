#include <iostream>

#include "Array.hpp"

int main() {
    size_t size = 5;

    // 예시 1) int 배열
    Array<int> int_arr(5);
    for (size_t i = 0; i < size; i++)
        int_arr[i] = i;

    for (size_t i = 0; i < size; i++)
        std::cout << int_arr[i] << " ";
    std::cout << std::endl << "size = " << int_arr.size() << std::endl;

    // 예시 2) char 배열
    Array<char> char_arr(5);
    for (size_t i = 0; i < size; i++)
        char_arr[i] = static_cast<char>('a' + i);

    for (size_t i = 0; i < size; i++)
        std::cout << char_arr[i] << " ";
    std::cout << std::endl << "size = " << char_arr.size() << std::endl;

    // 예시 3) out of range
    try {
        std::cout << int_arr[size] << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}