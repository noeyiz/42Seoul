#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << GRAY << "[ Brain ] Default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << GRAY << "[ Brain ] Copy constructor called" << RESET << std::endl;
    for (int i = 0; i < 100; i++) ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << GRAY << "[ Brain ] Copy assignment operator called" << RESET << std::endl;
    if (this != &other) for (int i = 0; i < 100; i++) ideas[i] = other.ideas[i];
    return *this;
}

Brain::~Brain(void) {
    std::cout << GRAY << "[ Brain ] Destructor called" << RESET << std::endl;
}

