#include "Cat.hpp"

Cat::Cat(void) {
    std::cout << GRAY << "[ Cat ] Default constructor called" << RESET << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& other) {
    std::cout << GRAY << "[ Cat ] Copy constructor called" << RESET << std::endl;
    type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << GRAY << "[ Cat ] Copy assignment operator called" << RESET << std::endl;
    if (this != &other) type = other.type;
    return *this;
}

Cat::~Cat(void) {
    std::cout << GRAY << "[ Cat ] Destructor called" << RESET << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "[ Cat ] miyaong ~" << std::endl;
}
