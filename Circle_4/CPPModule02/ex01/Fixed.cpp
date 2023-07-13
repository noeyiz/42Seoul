#include "./Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->raw_bits = 0;
}

Fixed::Fixed(const int raw) {
    std::cout << "Int constructor called" << std::endl;
    this->raw_bits = raw << fractional_bits;
}

Fixed::Fixed(const float raw) {
    std::cout << "Float constructor called" << std::endl;
    this->raw_bits = roundf(raw * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    this->raw_bits = other.raw_bits;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        std::cout << "Copy assignment operator called" << std::endl;
        this->raw_bits = other.raw_bits;
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
