#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->name = name;
    this->weapon = nullptr;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}

void HumanB::attack(void) {
    if (weapon != nullptr)
        std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
    else
        std::cout << name << " has no weapons ..." << std::endl;
}
