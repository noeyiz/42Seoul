#include "./Fixed.hpp"

/*
    KEYWORD: 연산자 오버로딩
*/

void check_leak(void) {
    system("leaks ex02 | grep leaked");
}

int main(void) {
    atexit(check_leak);

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}