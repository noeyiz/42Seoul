#include "ClapTrap.hpp"

// 오잉 기본 생성자 이름은 어떻게 한담 ?
ClapTrap::ClapTrap() : name("jikoo"), hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << GRAY << "Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << GRAY << "String constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << GRAY << "Copy constructor called" << RESET << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        std::cout << GRAY << "Copy assignment operator called" << RESET << std::endl;
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << GRAY << "Destructor called" << RESET << std::endl;
}

std::string ClapTrap::getName() const {
    return name;
}

unsigned int ClapTrap::getHitPoints() const {
    return hit_points;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return energy_points;
}

unsigned int ClapTrap::getAttackDamage() const {
    return attack_damage;
}

bool ClapTrap::checkPoints() {
    if (hit_points == 0) {
        std::cout << RED << "ClapTrap " << name << " is dead ..." << RESET << std::endl;
        return false;
    } else if (energy_points == 0) {
        std::cout << RED << "ClapTrap " << name << " is out of energy ..." << RESET << std::endl;
        return false;
    }
    return true;
}

void ClapTrap::showPoints() {
    std::cout << CYAN << "Energy [";
    for (unsigned int i = 0; i < energy_points; i++)
        std::cout << "⚡️";
    for (unsigned int i = 0; i < 10 - energy_points; i++)
        std::cout << "⬛️";
    std::cout << "] Health [";
    for (unsigned int i = 0; i < hit_points; i++)
        std::cout << "🤍";
    for (unsigned int i = 0; i < 10 - hit_points; i++)
        std::cout << "⬛️";
    std::cout << "]\n" << RESET << std::endl;
}

void ClapTrap::setLimitedHitPoints(int point) {
    if (point > 10) hit_points = 10;
    else if (point <= 0) hit_points = 0;
    else hit_points = point;
}

void ClapTrap::setLimitedEnergyPoints(int point) {
    if (point > 10) energy_points = 10;
    else if (point <= 0) energy_points = 0;
    else energy_points = point;
}

void ClapTrap::attack(const std::string& target) {
    if (checkPoints()) {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
        setLimitedEnergyPoints(energy_points - 1);
        showPoints();
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (checkPoints()) {
        std::cout << "ClapTrap " << name << " takes " << amount << " damage!" << std::endl;
        setLimitedHitPoints(hit_points - amount);
        showPoints();
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (checkPoints()) {
        std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points!" << std::endl;
        setLimitedHitPoints(hit_points + amount);
        setLimitedEnergyPoints(energy_points - 1);
        showPoints();
    }
}
