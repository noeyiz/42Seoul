#include <iostream>

/*
    KEYWORD: 포인터와 레퍼런스

    1. 레퍼런스는 반드시 선언과 동시에 초기화되어야 한다.
    2. 레퍼런스는 한 번 어떤 변수의 참조자가 되면, 더이상 다른 변수를 참조할 수 없다.
    3. 레퍼런스는 메모리 상에 존재하지 않을 수도 있다.
*/

int main(void) {
    std::string  stringVAR = "HI THIS IS BRAIN";
    std::string* stringPTR = &stringVAR;
    std::string& stringREF = stringVAR;

    std::cout << "=========  MEMORY ADDRESS  =========" << std::endl;
    std::cout << "string variable  : " << &stringVAR << std::endl;
    std::cout << "string pointer   : " << stringPTR << std::endl;
    std::cout << "string reference : " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "==============  VALUE  ==============" << std::endl;
    std::cout << "string variable  : " << stringVAR << std::endl;
    std::cout << "string pointer   : " << *stringPTR << std::endl;
    std::cout << "string reference : " << stringREF << std::endl;

    return 0;
}