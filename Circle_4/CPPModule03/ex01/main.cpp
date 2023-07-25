#include "ScavTrap.hpp"

int main(void) {
    ScavTrap jelly("jelly");

    jelly.attack("candy");
    jelly.takeDamage(30);
    jelly.beRepaired(40);
    jelly.guardGate();

    return 0;
}