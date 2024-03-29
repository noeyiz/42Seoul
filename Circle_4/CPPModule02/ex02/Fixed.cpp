#include "Fixed.hpp"

Fixed::Fixed(void) {
    std::cout << GRAY << "Default constructor called" << RESET << std::endl;
    value = 0;
}

Fixed::Fixed(const int num) {
    std::cout << GRAY << "Int constructor called" << RESET << std::endl;
    value = num << bits;
}

Fixed::Fixed(const float num) {
    std::cout << GRAY << "Float constructor called" << RESET << std::endl;
    value = static_cast<int>(roundf(num * (1 << bits)));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << GRAY << "Copy constructor called" << RESET << std::endl;
    value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << GRAY << "Copy assignment operator called" << RESET << std::endl;
    if (this != &other) value = other.getRawBits();
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << GRAY << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << GRAY << "getRawBits member function called" << RESET << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << GRAY << "setRawBits member function called" << RESET << std::endl;
    value = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(value) / (1 << bits);
}

int Fixed::toInt(void) const {
    return value >> bits;
}

bool Fixed::operator>(const Fixed& other) {
    return toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed& other) {
    return toFloat() < other.toFloat();
}

bool Fixed::operator>=(const Fixed& other) {
    return toFloat() >= other.toFloat();
}

bool Fixed::operator<=(const Fixed& other) {
    return toFloat() <= other.toFloat();
}

bool Fixed::operator==(const Fixed& other) {
    return toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed& other) {
    return toFloat() != other.toFloat();
}

Fixed Fixed::operator+(const Fixed& other) {
    Fixed result(toFloat() + other.toFloat());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) {
    Fixed result(toFloat() - other.toFloat());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) {
    Fixed result(toFloat() * other.toFloat());
    return result;
}

Fixed Fixed::operator/(const Fixed& other) {
    if (other.toFloat() == 0) {
        std::cout << RED << "Error: division by zero" << RESET << std::endl;
        exit(1);
    }
    Fixed result(toFloat() / other.toFloat());
    return result;
}

Fixed& Fixed::operator++(void) {
    value += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    value += 1;
    return temp;
}

Fixed& Fixed::operator--(void) {
    value -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    value -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed& one, Fixed &other) {
    return (one.getRawBits() < other.getRawBits()) ? one : other;
}

const Fixed& Fixed::min(const Fixed& one, const Fixed &other) {
    return (one.getRawBits() < other.getRawBits()) ? one : other;
}

Fixed& Fixed::max(Fixed& one, Fixed &other) {
    return (one.getRawBits() > other.getRawBits()) ? one : other;
}

const Fixed& Fixed::max(const Fixed& one, const Fixed &other) {
    return (one.getRawBits() > other.getRawBits()) ? one : other;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
