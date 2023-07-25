#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
    std::cout << GRAY << "[ WrongCat ] Default constructor called" << RESET << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) {
    std::cout << GRAY << "[ WrongCat ] Copy constructor called" << RESET << std::endl;
    this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << GRAY << "[ WrongCat ] Copy assignment operator called" << RESET << std::endl;
    if (this != &other) type = other.type;
    return *this;
}

WrongCat::~WrongCat(void) {
    std::cout << GRAY << "[ WrongCat ] Destructor called" << RESET << std::endl;
}

void WrongCat::makeSound(void) const {
    std::cout << "[ WrongCat ] miyaong ~" << std::endl;
}
