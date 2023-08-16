#include "Bureaucrat.hpp"

# define RESET		"\033[0m"
# define RED		"\033[1;91m"

int main(void) {
    try {
        Bureaucrat a("a", 2);
        std::cout << a << std::endl;
        a.increaseGrade();
        std::cout << a << std::endl;
        a.increaseGrade();
        // a.decreaseGrade();
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