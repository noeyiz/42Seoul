#include "Dog.hpp"

Dog::Dog(void) {
    std::cout << GRAY << "[ Dog ] Default constructor called" << RESET << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog& other) {
    std::cout << GRAY << "[ Dog ] Copy constructor called" << RESET << std::endl;
    type = other.type;
    brain = new Brain(*(other.brain));
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << GRAY << "[ Dog ] Copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        type = other.type;
        delete brain;
        brain = new Brain(*(other.brain));
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
