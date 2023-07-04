#include "./Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void) {
    int n = 5;
    std::string name = "jikoo zombie";

    Zombie* horde = zombieHorde(n, name);
    for (int i = 0; i < n; i++)
        horde[i].announce();
    delete[] horde;

    return 0;
}