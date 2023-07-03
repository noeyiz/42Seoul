#include "./Zombie.hpp"

void    randomChump(std::string name);
Zombie* newZombie(std::string name);

/*
    KEYWORK: 정적 할당과 동적 할당

    1. 어디에 저장되나? : 스택 / 힙
    2. 객체 생성 시점은? : 컴파일 시점 / 런타임
    3. 할당 해제 방법은? : 함수 종료 시 자동으로 / delete 연산자
*/

int main(void) {
    randomChump("static");

    Zombie *zombie_dynamic = newZombie("dynamic");
    zombie_dynamic->announce();
    delete zombie_dynamic;

    return 0;
}