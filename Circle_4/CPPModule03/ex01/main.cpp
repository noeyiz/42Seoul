#include "ScavTrap.hpp"

int main(void) {
    ScavTrap jelly("jelly");

    jelly.attack("candy");
    jelly.takeDamage(3);
    jelly.beRepaired(2);
    jelly.guardGate();

    return 0;
}