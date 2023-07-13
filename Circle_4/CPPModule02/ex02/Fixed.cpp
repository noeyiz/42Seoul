#include "./Fixed.hpp"

Fixed::Fixed() {
    setRawBits(0);
}

Fixed::Fixed(const int raw) {
    setRawBits(raw << fractional_bits);
}

Fixed::Fixed(const float raw) {
    setRawBits(roundf(raw * (1 << fractional_bits)));
}

Fixed::Fixed(const Fixed& other) {
    setRawBits(other.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        setRawBits(other.getRawBits());
    return *this;
}

Fixed::~Fixed() {}

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
    float new_raw = toFloat() + other.toFloat();
    setRawBits(roundf(new_raw * (1 << fractional_bits)));

    return *this;
}

Fixed& Fixed::operator-(const Fixed& other) {
    float new_raw = toFloat() - other.toFloat();
    setRawBits(roundf(new_raw * (1 << fractional_bits)));

    return *this;
}

Fixed& Fixed::operator*(const Fixed& other) {
    float new_raw = toFloat() * other.toFloat();
    setRawBits(roundf(new_raw * (1 << fractional_bits)));

    return *this;
}

Fixed& Fixed::operator/(const Fixed& other) {
    if (other.toFloat() == 0) {
        std::cout << RED << "Error: division by zero" << RESET << std::endl;
        exit(1);
    }

    float new_raw = toFloat() / other.toFloat();
    setRawBits(roundf(new_raw * (1 << fractional_bits)));

    return *this;
}

Fixed& Fixed::operator++(void) {
    setRawBits(raw_bits + 1);

    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    setRawBits(raw_bits + 1);

    return temp;
}

Fixed& Fixed::operator--(void) {
    setRawBits(raw_bits - 1);

    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    setRawBits(raw_bits - 1);

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
