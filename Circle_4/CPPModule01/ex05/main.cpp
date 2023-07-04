#include "./Harl.hpp"

/*
    KEYWORD: 클래스 함수 포인터의 사용
*/

int main(void) {
    Harl harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    return 0;
}