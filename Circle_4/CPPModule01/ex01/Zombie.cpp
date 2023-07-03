#include "Zombie.hpp"

Zombie::~Zombie() {
    std::cout << name << ": Die..." << std::endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
