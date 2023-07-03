#include "HumanA.hpp"
#include "HumanB.hpp"

/*
    KEYWORD: 포인터와 레퍼런스

    1. 레퍼런스의 사용 이유 : 한번 초기화되면 다른 객체를 참조할 수 없으므로 포인터보다 안전
    2. 포인터를 사용해야만 할 때 ? : 옵셔널일 때
*/

int main(void) {
    {
    Weapon club = Weapon("crude spiked club");

    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    }

    {
    Weapon club = Weapon("crude spiked club");

    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
    }

    return 0;
}