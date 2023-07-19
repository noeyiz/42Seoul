#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("null", 100, 50, 20) {
    std::cout << GRAY << "ScavTrap Default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
    std::cout << GRAY << "ScavTrap String constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other.name, other.hit_points, other.energy_points, other.attack_damage) {
    std::cout << GRAY << "ScavTrap Copy constructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        std::cout << GRAY << "ScavTrap Copy assignment operator called" << RESET << std::endl;
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << GRAY << "ScavTrap Destructor called" << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (isAnyPointsZero()) return;

    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
    setLimitedEnergyPoints(energy_points - 1);
    showPoints();
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}
