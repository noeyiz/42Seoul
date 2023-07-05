#include "./Fixed.hpp"

/*
    KEYWORD : 복사 생성자와 복사 대입 연산자

    1. 복사 생성자는 인자로 받은 객체를 복사하여 객체를 생성한다.
    2. 복사 대입 연산자는 기본 생성자로 객체를 생성한 후, 인자로 받은 객체의 값을 복사한다.

    # 깊은 복사와 얕은 복사?
    # 복사 생성자 안에서 복사 대입 연산자를 호출
        : 복사 대입 연산자의 동작을 재사용하여 중복을 피하고 일관성 유지 가능
          일반적으로 권장되는 방식은 아님 ... 복사 생성자는 *복사 생성*의 목적을 가지고 있고
          복사 대입 연산자는 이미 할당된 *객체에 값을 대입*하는 목적으로 가지고 있기 때문 !
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