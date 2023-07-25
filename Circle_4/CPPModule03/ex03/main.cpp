#include "DiamondTrap.hpp"

int main(void) {
    DiamondTrap jelly("jelly");

    jelly.attack("candy");
    jelly.takeDamage(30);
    jelly.beRepaired(40);
    jelly.whoAmI();

    return 0;
}