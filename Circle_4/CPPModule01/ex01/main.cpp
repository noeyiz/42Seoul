#include "./Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

/*
    KEYWORK: 객체 배열 동적 할당

    1. 메모리 할당 : 클래스이름* 배열이름 = new 클래스이름[배열의크기];
    2. 메모리 해제 : delete[] 배열이름;
*/

int main(void) {
    int n = 5;
    std::string name = "jikoo zombie";

    Zombie* horde = zombieHorde(n, name);
    for (int i = 0; i < n; i++)
        horde[i].announce();
    delete[] horde;

    return 0;
}