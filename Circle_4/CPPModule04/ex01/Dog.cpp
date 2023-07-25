#include "Dog.hpp"

Dog::Dog(void) {
    std::cout << GRAY << "[ Dog ] Default constructor called" << RESET << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog& other) {
    std::cout << GRAY << "[ Dog ] Copy constructor called" << RESET << std::endl;
    this->type = other.type;
    this->brain = new Brain();
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << GRAY << "[ Dog ] Copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        type = other.type;
        delete brain;
        brain = new Brain();
    }
    return *this;
}

Dog::~Dog(void) {
    delete brain;
    std::cout << GRAY << "[ Dog ] Destructor called" << RESET << std::endl;
}

void Dog::makeSound(void) const {
    std::cout << "[ Dog ] wang wang!" << std::endl;
}
