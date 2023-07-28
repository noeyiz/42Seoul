#include "AAnimal.hpp"

AAnimal::AAnimal(void) {
    std::cout << GRAY << "[ AAnimal ] Default constructor called" << RESET << std::endl;
    type = "(null)";
}

AAnimal::AAnimal(const AAnimal& other) {
    std::cout << GRAY << "[ AAnimal ] Copy constructor called" << RESET << std::endl;
    type = other.type;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << GRAY << "[ AAnimal ] Copy assignment operator called" << RESET << std::endl;
    if (this != &other) type = other.type;
    return *this;
}

AAnimal::~AAnimal(void) {
    std::cout << GRAY << "[ AAnimal ] Destructor called" << RESET << std::endl;
}

std::string AAnimal::getType(void) const {
    return type;
}
