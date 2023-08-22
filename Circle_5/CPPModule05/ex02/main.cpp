#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
    try {
        Bureaucrat bureaucrat("bureaucrat", 1);
        // Bureaucrat bureaucrat("bureaucrat", 50);
        // Bureaucrat bureaucrat("bureaucrat", 150);
        std::cout << bureaucrat << "\n" << std::endl;

        AForm *shrubberyCreationForm = new ShrubberyCreationForm("A");
        std::cout << *shrubberyCreationForm << std::endl;
        AForm *robotomyRequestForm = new RobotomyRequestForm("B");
        std::cout << *robotomyRequestForm << std::endl;
        AForm *presidentialPardonForm = new PresidentialPardonForm("C");
        std::cout << *presidentialPardonForm << "\n" << std::endl;

        bureaucrat.signForm(*shrubberyCreationForm);
        bureaucrat.executeForm(*shrubberyCreationForm);
        std::cout << std::endl;
        
        bureaucrat.signForm(*robotomyRequestForm);
        bureaucrat.executeForm(*robotomyRequestForm);
        std::cout << std::endl;
        
        bureaucrat.signForm(*presidentialPardonForm);
        bureaucrat.executeForm(*presidentialPardonForm);
        std::cout << std::endl;

        delete shrubberyCreationForm;
        delete robotomyRequestForm;
        delete presidentialPardonForm;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}