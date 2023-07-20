#include "./Fixed.hpp"

Fixed::Fixed(void) : value(0) {
    std::cout << GRAY << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int num) {
    std::cout << GRAY << "Int constructor called" << RESET << std::endl;
    value = num << bits;
}

Fixed::Fixed(const float num) {
    std::cout << GRAY << "Float constructor called" << RESET << std::endl;
    value = roundf(num * (1 << bits));
}

Fixed::Fixed(const Fixed& other) : value(other.getRawBits()) {
    std::cout << GRAY << "Copy constructor called" << RESET << std::endl;
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

Fixed& Fixed::operator+(const Fixed& other) {
    float num = toFloat() + other.toFloat();
    value = round(num * (1 << bits));
    return *this;
}

Fixed& Fixed::operator-(const Fixed& other) {
    float num = toFloat() - other.toFloat();
    value = round(num * (1 << bits));
    return *this;
}

Fixed& Fixed::operator*(const Fixed& other) {
    float num = toFloat() * other.toFloat();
    value = round(num * (1 << bits));
    return *this;
}

Fixed& Fixed::operator/(const Fixed& other) {
    if (other.toFloat() == 0) {
        std::cout << RED << "Error: division by zero" << RESET << std::endl;
        exit(1);
    }
    float num = toFloat() / other.toFloat();
    value = round(num * (1 << bits));
    return *this;
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
