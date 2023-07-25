#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("_clap_name", 100, 50, 30, 100, 50), name("(null)") {
    std::cout << GRAY << "[ DiamondTrap ] " << name << " : Default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name", 100, 50, 30, 100, 50), name(name) {
    std::cout << GRAY << "[ DiamondTrap ] " << name << " : String constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : 
    ClapTrap(
        other.name + "_clap_name", 
        other.hit_points, 
        other.energy_points, 
        other.attack_damage, 
        other.max_hit_points, 
        other.max_energy_points
    ), name(other.name) {
    std::cout << GRAY << "[ DiamondTrap ] " << name << " : Copy constructor called" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << GRAY << "[ DiamondTrap ] " << name << " : Copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        this->name = other.name;
        ClapTrap::name = name + "_clap_name";
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
        this->max_hit_points = other.max_hit_points;
        this->max_energy_points = other.max_energy_points;
    }
    return *this;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << GRAY << "[ DiamondTrap ] " << name << " : Destructor called" << RESET << std::endl;
}

void DiamondTrap::whoAmI(void) {
    std::cout << "[ DiamondTrap ] I am " << name << ", " << ClapTrap::name << std::endl;
}
