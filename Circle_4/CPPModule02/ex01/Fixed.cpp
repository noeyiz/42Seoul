#include "./Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->value = value << this->fractional_bits;
    std::cout << CYAN << value << " : " << this->value << RESET << std::endl; /////////////
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(value * (1 << this->fractional_bits));
    std::cout << CYAN << value << " : " << this->value << RESET << std::endl; /////////////
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    this->value = other.value;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

int Fixed::toInt(void) const {
    return this->value >> this->fractional_bits;
}

float Fixed::toFloat(void) const {
    return (float)this->value / (1 << this->fractional_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
