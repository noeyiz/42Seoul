#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
    std::cout << GRAY << "[ WrongCat ] Default constructor called" << RESET << std::endl;
    type = "WrongCat";
    brain = new Brain();
}

WrongCat::WrongCat(const WrongCat& other) {
    std::cout << GRAY << "[ WrongCat ] Copy constructor called" << RESET << std::endl;
    type = other.type;
    brain = other.brain;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << GRAY << "[ WrongCat ] Copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        type = other.type;
        brain = other.brain;
    }
    return *this;
}

WrongCat::~WrongCat(void) {
    delete brain;
    std::cout << GRAY << "[ WrongCat ] Destructor called" << RESET << std::endl;
}

void WrongCat::makeSound(void) const {
    std::cout << "[ WrongCat ] miyaong ~" << std::endl;
}
