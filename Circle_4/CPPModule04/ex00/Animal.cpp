#include "Animal.hpp"

Animal::Animal(void) {
    std::cout << GRAY << "[ Animal ] Default constructor called" << RESET << std::endl;
    type = "(null)";
}

Animal::Animal(const Animal& other) {
    std::cout << GRAY << "[ Animal ] Copy constructor called" << RESET << std::endl;
    type = other.type;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << GRAY << "[ Animal ] Copy assignment operator called" << RESET << std::endl;
    if (this != &other) type = other.type;
    return *this;
}

Animal::~Animal(void) {
    std::cout << GRAY << "[ Animal ] Destructor called" << RESET << std::endl;
}

std::string Animal::getType(void) const {
    return type;
}

void Animal::makeSound(void) const {
    std::cout << "[ Animal ] ...?" << std::endl;
}
