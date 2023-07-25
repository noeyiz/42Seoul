#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("(null)", 100, 100, 30, 100, 100) {
    std::cout << GRAY << "[ FragTrap ] " << name << " : Default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30, 100, 100) {
    std::cout << GRAY << "[ FragTrap ] " << name << " : String constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : 
    ClapTrap(
        other.name, 
        other.hit_points, 
        other.energy_points, 
        other.attack_damage, 
        other.max_hit_points, 
        other.max_energy_points
    ) {
    std::cout << GRAY << "[ FragTrap ] " << name << " : Copy constructor called" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << GRAY << "[ FragTrap ] " << name << " : Copy assignment operator called" << RESET << std::endl;
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

FragTrap::~FragTrap(void) {
    std::cout << GRAY << "[ FragTrap ] " << name << " : Destructor called" << RESET << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "[ FragTrap ] " << name << " : high fives guys!!!" << std::endl;
}
