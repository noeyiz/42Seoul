#include "Cat.hpp"

Cat::Cat(void) {
    std::cout << GRAY << "[ Cat ] Default constructor called" << RESET << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat& other) {
    std::cout << GRAY << "[ Dog ] Copy constructor called" << RESET << std::endl;
    this->type = other.type;
    this->brain = other.brain;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << GRAY << "[ Cat ] Copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        type = other.type;
        delete brain;
        brain = other.brain;
    }
    return *this;
}

Cat::~Cat(void) {
    delete brain;
    std::cout << GRAY << "[ Cat ] Destructor called" << RESET << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "[ Cat ] wang wang!" << std::endl;
}