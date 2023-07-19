#include "ClapTrap.hpp"

/*
    attack(target) : energy point 1 감소
    takeDamage(amount) : attack damage만큼 hit points를 잃게 됨
    beRepaired(amount) : energy point 1 감소, amount만큼 hit points를 얻게 됨
*/

int main(void) {
    ClapTrap jelly("jelly");

    jelly.attack("candy");
    jelly.takeDamage(3);
    jelly.beRepaired(2);

    // // 에너지 모두 소모
    // for (int i = 0; i < 10; i++)
    //     jelly.attack("candy");

    // // 목숨이 다함
    // for (int i = 0; i < 10; i++)
    //     jelly.takeDamage(1);

    return 0;
}