#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("(null)", 100, 50, 20, 100, 50) {
    std::cout << GRAY << "[ ScavTrap ] " << name << " : Default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20, 100, 50) {
    std::cout << GRAY << "[ ScavTrap ] " << name << " : String constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : 
    ClapTrap(
        other.name, 
        other.hit_points, 
        other.energy_points, 
        other.attack_damage, 
        other.max_hit_points, 
        other.max_energy_points
    ) {
    std::cout << GRAY << "[ ScavTrap ] " << name << " : Copy constructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << GRAY << "[ ScavTrap ] " << name << " : Copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
        this->max_hit_points = other.max_hit_points;
        this->max_energy_points = other.max_energy_points;
    }
    return *this;
}

ScavTrap::~ScavTrap(void) {
    std::cout << GRAY << "[ ScavTrap ] " << name << " : Destructor called" << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (isAnyPointsZero(hit_points, energy_points)) return;

    std::cout << "[ ScavTrap ] " << name << " attacks " << target
        << ", causing " << attack_damage << " points of damage!" << std::endl;
    setLimitedEnergyPoints(energy_points - 1);
    showPoints();
}

void ScavTrap::guardGate(void) {
    std::cout << "[ ScavTrap ] " << name << " is now in Gate keeper mode!" << std::endl;
}
