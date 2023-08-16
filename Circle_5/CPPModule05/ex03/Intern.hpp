#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
private:
    std::string names[3];

public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(std::string name, std::string target);

    class InvalidTypeException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif // INTERN_HPP