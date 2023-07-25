#include "FragTrap.hpp"

int main(void) {
    FragTrap jelly("jelly");

    jelly.attack("candy");
    jelly.takeDamage(30);
    jelly.beRepaired(40);
    jelly.highFivesGuys();

    return 0;
}