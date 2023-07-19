#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : 
    name("null"), 
    hit_points(10), 
    energy_points(10), 
    attack_damage(0),
    initial_hit_points(10),
    initial_energy_points(10) {
    std::cout << GRAY << "ClapTrap Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : 
    name(name), 
    hit_points(10), 
    energy_points(10), 
    attack_damage(0),
    initial_hit_points(10),
    initial_energy_points(10) {
    std::cout << GRAY << "ClapTrap String constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hit_points, unsigned int energy_points, unsigned int attack_damage) :
    name(name),
    hit_points(hit_points),
    energy_points(energy_points),
    attack_damage(attack_damage),
    initial_hit_points(hit_points),
    initial_energy_points(energy_points) {
    std::cout << GRAY << "ClapTrap All attributes constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) :
    name(other.name),
    hit_points(other.hit_points),
    energy_points(other.energy_points),
    attack_damage(other.attack_damage),
    initial_hit_points(other.hit_points),
    initial_energy_points(other.energy_points) {
    std::cout << GRAY << "ClapTrap Copy constructor called" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        std::cout << GRAY << "ClapTrap Copy assignment operator called" << RESET << std::endl;
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << GRAY << "ClapTrap Destructor called" << RESET << std::endl;
}

bool ClapTrap::isAnyPointsZero() {
    if (hit_points == 0) {
        std::cout << RED << "ClapTrap " << name << " is dead ..." << RESET << std::endl;
        return true;
    } else if (energy_points == 0) {
        std::cout << RED << "ClapTrap " << name << " is out of energy ..." << RESET << std::endl;
        return true;
    }
    return false;
}

void ClapTrap::showPoints() {
    std::cout << CYAN << "Energy [";
    for (unsigned int i = 0; i < energy_points; i++)
        std::cout << "⚡️";
    for (unsigned int i = 0; i < initial_energy_points - energy_points; i++)
        std::cout << "⬛️";
    std::cout << "]\nHealth [";
    for (unsigned int i = 0; i < hit_points; i++)
        std::cout << "🤍";
    for (unsigned int i = 0; i < initial_hit_points - hit_points; i++)
        std::cout << "⬛️";
    std::cout << "]\n" << RESET << std::endl;
}

void ClapTrap::setLimitedHitPoints(int point) {
    if (point > initial_hit_points) hit_points = initial_hit_points;
    else if (point <= 0) hit_points = 0;
    else hit_points = point;
}

void ClapTrap::setLimitedEnergyPoints(int point) {
    if (point > initial_energy_points) energy_points = initial_energy_points;
    else if (point <= 0) energy_points = 0;
    else energy_points = point;
}

void ClapTrap::attack(const std::string& target) {
    if (isAnyPointsZero()) return;

    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
    setLimitedEnergyPoints(energy_points - 1);
    showPoints();
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (isAnyPointsZero()) return;
    
    std::cout << "ClapTrap " << name << " takes " << amount << " damage!" << std::endl;
    setLimitedHitPoints(hit_points - amount);
    showPoints();
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (isAnyPointsZero()) return;
    
    std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points!" << std::endl;
    setLimitedHitPoints(hit_points + amount);
    setLimitedEnergyPoints(energy_points - 1);
    showPoints();
}
