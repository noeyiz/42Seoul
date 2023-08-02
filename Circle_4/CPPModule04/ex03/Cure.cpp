#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other.type) {}

Cure& Cure::operator=(const Cure &other) {
    if (this != &other) type = other.type;
    return *this;
}

Cure::~Cure(void) {}

AMateria* Cure::clone(void) const {
    return new Cure();
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
