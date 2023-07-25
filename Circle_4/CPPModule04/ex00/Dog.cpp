#include "Dog.hpp"

Dog::Dog(void) {
    std::cout << GRAY << "[ Dog ] Default constructor called" << RESET << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& other) {
    std::cout << GRAY << "[ Dog ] Copy constructor called" << RESET << std::endl;
    this->type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << GRAY << "[ Dog ] Copy assignment operator called" << RESET << std::endl;
    if (this != &other) type = other.type;
    return *this;
}

Dog::~Dog(void) {
    std::cout << GRAY << "[ Dog ] Destructor called" << RESET << std::endl;
}

void Dog::makeSound(void) const {
    std::cout << "[ Dog ] wang wang!" << std::endl;
}
