#include "./Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    setRawBits(0);
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) { // 객체가 자기 자신에게 대입되는지 여부를 확인하기 위해 ... 안정성 보장 !
        std::cout << "Copy assignment operator called" << std::endl;
        setRawBits(other.getRawBits());
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}
