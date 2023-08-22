#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    try {
        Bureaucrat candy("candy", 1);
        std::cout << candy << std::endl;

        Bureaucrat choco("choco", 70);
        std::cout << choco << std::endl;
        
        Bureaucrat jelly("jelly", 150);
        std::cout << jelly << std::endl;

        Form form("important form", 100, 50);
        std::cout << form << std::endl;

        candy.signForm(form);
        choco.signForm(form);
        jelly.signForm(form);

        Form wrong_form("wrong form", 0, 0);
        std::cout << wrong_form << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    return 0;
}