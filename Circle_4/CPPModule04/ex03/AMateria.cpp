#include "AMateria.hpp"

AMateria::AMateria(void) : type("(null)") {}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& other) : type(other.type) {}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) type = other.type;
    return *this;
}

AMateria::~AMateria(void) {}

std::string const & AMateria::getType(void) const {
    return type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
    std::cout << "[ AMateria ] user function" << std::endl;
}
