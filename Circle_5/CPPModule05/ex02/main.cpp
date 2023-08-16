#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void check_leak() {
    system("leaks ex02 | grep leaked");
}

int main(void) {
    atexit(check_leak);

    try {
        Bureaucrat bureaucrat("bureaucrat", 1);
        // Bureaucrat bureaucrat("bureaucrat", 50);
        // Bureaucrat bureaucrat("bureaucrat", 150);
        std::cout << bureaucrat << "\n" << std::endl;

        AForm *a = new ShrubberyCreationForm("A");
        std::cout << *a << std::endl;
        AForm *b = new RobotomyRequestForm("B");
        std::cout << *b << std::endl;
        AForm *c = new PresidentialPardonForm("C");
        std::cout << *c << "\n" << std::endl;

        bureaucrat.signForm(*a);
        bureaucrat.executeForm(*a);
        std::cout << std::endl;
        
        bureaucrat.signForm(*b);
        bureaucrat.executeForm(*b);
        std::cout << std::endl;
        
        bureaucrat.signForm(*c);
        bureaucrat.executeForm(*c);
        std::cout << std::endl;

        delete a;
        delete b;
        delete c;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}