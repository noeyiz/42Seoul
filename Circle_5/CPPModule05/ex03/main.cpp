#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
    try {
        Bureaucrat bureaucrat("bureaucrat", 1);
        // Bureaucrat bureaucrat("bureaucrat", 50);
        // Bureaucrat bureaucrat("bureaucrat", 150);
        std::cout << bureaucrat << "\n" << std::endl;

        Intern somRandomIntern;

        AForm *rrf = somRandomIntern.makeForm("shrubbery creation", "Bender");
        // AForm *rrf = somRandomIntern.makeForm("robotomy request", "Bender");
        // AForm *rrf = somRandomIntern.makeForm("presidential pardon", "Bender");
        // AForm *rrf = somRandomIntern.makeForm("blabla ..", "Bender");
        std::cout << *rrf << "\n" << std::endl;

        bureaucrat.signForm(*rrf);
        bureaucrat.executeForm(*rrf);
        std::cout << std::endl;

        delete rrf;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}