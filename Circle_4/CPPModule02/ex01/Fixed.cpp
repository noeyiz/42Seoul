#include "./Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    
}

Fixed::Fixed(const int number) {
    std::cout << "Int constructor called" << std::endl;

}

Fixed::Fixed(const float number) {
    std::cout << "Float constructor called" << std::endl;

}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;

}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;

}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;

}

std::ostream& Fixed::operator<<(std::ostream& os) {

}

float Fixed::toFloat(void) const {
    return 0.0;
}

int Fixed::toInt(void) const {
    return 0;
}
