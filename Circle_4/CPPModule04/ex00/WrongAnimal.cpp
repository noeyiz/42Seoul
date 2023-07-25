#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
    std::cout << GRAY << "[ WrongAnimal ] Default constructor called" << RESET << std::endl;
    this->type = "(null)";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << GRAY << "[ WrongAnimal ] Copy constructor called" << RESET << std::endl;
    this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << GRAY << "[ WrongAnimal ] Copy assignment operator called" << RESET << std::endl;
    if (this != &other) type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << GRAY << "[ WrongAnimal ] Destructor called" << RESET << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return type;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "[ WrongAnimal ] ...?" << std::endl;
}
