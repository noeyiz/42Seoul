#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : 
    name("(null)"), 
    hit_points(MAX_HIT), 
    energy_points(MAX_ENERGY), 
    attack_damage(0) {
    std::cout << GRAY << "[ ClapTrap ] " << name << " : Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : 
    name(name), 
    hit_points(MAX_HIT), 
    energy_points(MAX_ENERGY), 
    attack_damage(0) {
    std::cout << GRAY << "[ ClapTrap ] " << name << " : String constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : 
    name(other.name), 
    hit_points(other.hit_points), 
    energy_points(other.energy_points), 
    attack_damage(other.attack_damage) {
    std::cout << GRAY << "[ ClapTrap ] " << name << " : Copy constructor called" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << GRAY << "[ ClapTrap ] " << name << " : Copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

ClapTrap::~ClapTrap(void) {
    std::cout << GRAY << "[ ClapTrap ] " << name << " : Destructor called" << RESET << std::endl;
}

void ClapTrap::setLimitedHitPoints(int point) {
    if (point <= 0) hit_points = 0;
    else if (point > MAX_HIT) hit_points = MAX_HIT;
    else hit_points = point;
}

void ClapTrap::setLimitedEnergyPoints(int point) {
    if (point <= 0) energy_points = 0;
    else if (point > MAX_ENERGY) energy_points = MAX_ENERGY;
    else energy_points = point;
}

bool ClapTrap::isAnyPointsZero(unsigned int hit, unsigned int energy) {
    if (hit == 0) {
        std::cout << RED << "[ ClapTrap ] " << name << " is dead ..." << RESET << std::endl;
        return true;
    } else if (energy == 0) {
        std::cout << RED << "[ ClapTrap ] " << name << " is out of energy ..." << RESET << std::endl;
        return true;
    }
    return false;
}

void ClapTrap::showPoints(void) {
    std::cout << CYAN;
    std::cout << "💖 [" << hit_points << "/" << MAX_HIT << "]" << "  ";
    std::cout << "💪 [" << energy_points << "/" << MAX_ENERGY << "]";
    std::cout << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (isAnyPointsZero(hit_points, energy_points)) return;

    std::cout << "[ ClapTrap ] " << name << " attacks " << target
        << ", causing " << attack_damage << " points of damage!" << std::endl;
    setLimitedEnergyPoints(energy_points - 1);
    showPoints();
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (isAnyPointsZero(hit_points, MAX_ENERGY)) return;
    
    std::cout << "[ ClapTrap ] " << name << " takes " << amount << " damage!" << std::endl;
    setLimitedHitPoints(hit_points - amount);
    showPoints();
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (isAnyPointsZero(hit_points, energy_points)) return;
    
    std::cout << "[ ClapTrap ] " << name << " repairs itself for " << amount << " hit points!" << std::endl;
    setLimitedHitPoints(hit_points + amount);
    setLimitedEnergyPoints(energy_points - 1);
    showPoints();
}
