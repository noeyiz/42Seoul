#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat a("a", 2);
        std::cout << a << std::endl;
        a.increaseGrade();
        std::cout << a << std::endl;
        a.increaseGrade();
        std::cout << a << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat b("b", 151);
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    return 0;
}