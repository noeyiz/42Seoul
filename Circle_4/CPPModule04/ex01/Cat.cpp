#include "Cat.hpp"

Cat::Cat(void) {
    std::cout << GRAY << "[ Cat ] Default constructor called" << RESET << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat& other) {
    std::cout << GRAY << "[ Cat ] Copy constructor called" << RESET << std::endl;
    type = other.type;
    brain = new Brain(*(other.brain));
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << GRAY << "[ Cat ] Copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        type = other.type;
        delete brain;
        brain = new Brain(*(other.brain));
    }
    return *this;
}

Cat::~Cat(void) {
    delete brain;
    std::cout << GRAY << "[ Cat ] Destructor called" << RESET << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "[ Cat ] miyaong ~" << std::endl;
}
