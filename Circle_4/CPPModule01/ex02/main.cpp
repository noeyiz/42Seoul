#include <iostream>

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