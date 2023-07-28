#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice& other) : AMateria(other.type) {}

Ice& Ice::operator=(const Ice &other) {
    if (this != &other) type = other.type;
}

Ice::~Ice(void) {}

AMateria* Ice::clone(void) const {
    return new Ice();
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
