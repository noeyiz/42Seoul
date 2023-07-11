#include "./Fixed.hpp"

/*
    KEYWORD : 복사 생성자와 복사 대입 연산자
*/

void check_leak(void) {
    system("leaks ex00 | grep leaked");
}

int main(void) {
    atexit(check_leak);

    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}