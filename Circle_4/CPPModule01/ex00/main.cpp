#include "./Zombie.hpp"

void    randomChump(std::string name);
Zombie* newZombie(std::string name);

int main(void) {
    randomChump("static");

    Zombie *zombie_dynamic = newZombie("dynamic");
    zombie_dynamic->announce();
    delete zombie_dynamic;

    return 0;
}