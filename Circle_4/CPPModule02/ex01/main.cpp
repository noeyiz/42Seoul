#include "./Fixed.hpp"

/*
    KEYWORD: 오버로딩과 고정 소수점
    
    # 오버로딩 :
        std::cout << obj << std::endl; 와 같은 형식으로 사용하려면 비멤버 함수로 << 연산자를 오버로딩 해야 한다.
        비멤버 함수로 연산자를 오버로딩하면 해당 연산자가 클래스의 멤버가 아닌 다른 객체와의 연산으로 작동한다.
*/
int main(void) {
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}