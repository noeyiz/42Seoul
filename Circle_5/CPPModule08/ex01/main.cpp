#include <iostream>

#include "Span.hpp"

#define RESET	"\033[0m"
#define RED		"\033[1;91m"

int main() {
    try {
        // Span sp(5);
        // Span sp(10);
        Span sp(15);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        // 예시 1) 사이즈 초과 !!!
        sp.addNumber(2);

        // 예시 2 ) 한번에 넣기 !!!
        std::vector<int> vector;
        for (int i = 0; i < 5; i++)
            vector.push_back(i);
        sp.addNumbers<std::vector<int> >(vector.begin(), vector.end());

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}