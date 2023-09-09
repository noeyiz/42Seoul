#include <iostream>

#include "Array.hpp"

#define RESET	"\033[0m"
#define RED	    "\033[1;91m"

int main() {
    size_t size = 5;
    try {
        // 예시 1) int 배열
        Array<int> int_arr(size);
        for (size_t i = 0; i < int_arr.size(); i++)
            int_arr[i] = i;
        
        for (size_t i = 0; i < int_arr.size(); i++)
            std::cout << int_arr[i] << " ";
        std::cout << std::endl;

        // 예시 2) char 배열
        Array<char> char_arr(size);
        for (size_t i = 0; i < char_arr.size(); i++)
            char_arr[i] = static_cast<char>('a' + i);

        for (size_t i = 0; i < char_arr.size(); i++)
            std::cout << char_arr[i] << " ";
        std::cout << std::endl;

    // 예시 3) out of range
        std::cout << int_arr[size] << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    return 0;
}