#include "./Fixed.hpp"

/*
    KEYWORD : 복사 생성자와 복사 대입 연산자
    // 객체가 자기 자신에게 대입되는지 여부를 확인하기 위해 ... 안정성 보장 !
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