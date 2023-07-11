#include "./Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    setRawBits(0);
}

Fixed::Fixed(const int raw) {
    std::cout << "Int constructor called" << std::endl;
    if (raw > (INT_MAX >> fractional_bits) || raw < (INT_MIN >> fractional_bits)) {
        std::cerr << RED << "Out of range: " << RESET << "initialize to the default value of 0" << std::endl;
        setRawBits(0);
    } else {
        setRawBits(raw << fractional_bits);
    }
}

Fixed::Fixed(const float raw) {
    std::cout << "Float constructor called" << std::endl;
    if (raw > (INT_MAX >> fractional_bits) || raw < (INT_MIN >> fractional_bits)) {
        std::cerr << RED << "Out of range: " << RESET << "initialize to the default value of 0" << std::endl;
        setRawBits(0);
    } else {
        setRawBits(roundf(raw * (1 << fractional_bits)));
    }
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    setRawBits(other.getRawBits());
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
    return raw_bits;
}

void Fixed::setRawBits(int const raw) {
    raw_bits = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(raw_bits) / (1 << fractional_bits);
}

int Fixed::toInt(void) const {
    return raw_bits >> fractional_bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
