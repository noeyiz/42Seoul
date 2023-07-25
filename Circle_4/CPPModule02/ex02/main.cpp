#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    /* test */
    Fixed c(42);
    Fixed d(4.2f);

    std::cout << "42 > 4.2 : " << (c > d) << std::endl;
    std::cout << "42 < 4.2 : " << (c < d) << std::endl;
    std::cout << "42 >= 4.2 : " << (c >= d) << std::endl;
    std::cout << "42 <= 4.2 : " << (c <= d) << std::endl;
    std::cout << "42 == 4.2 : " << (c == d) << std::endl;
    std::cout << "42 != 4.2 : " << (c != d) << std::endl;

    std::cout << "42 + 4.2 = " << c + d << std::endl;
    std::cout << "42 - 4.2 = " << c - d << std::endl;
    std::cout << "42 * 4.2 = " << c * d << std::endl;
    std::cout << "42 / 4.2 = " << c / d << std::endl;

    // std::cout << Fixed(2) / Fixed(0) << std::endl;

    return 0;
}