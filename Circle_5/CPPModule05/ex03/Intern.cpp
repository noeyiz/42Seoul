#include "Intern.hpp"

Intern::Intern() {
    names[0] = "shrubbery creation";
    names[1] = "robotomy request";
    names[2] = "presidential pardon";
}

Intern::Intern(const Intern& other) {
    for (int i = 0; i < 3; i++) names[i] = other.names[i];
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {
        for (int i = 0; i < 3; i++) names[i] = other.names[i];
    }
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string name, std::string target) {
    int idx = 0;
    while (idx < 3) {
        if (names[idx] == name) break;
        idx++;
    }

    switch (idx) {
    case 0: return new ShrubberyCreationForm(target);
    case 1: return new RobotomyRequestForm(target);
    case 2: return new PresidentialPardonForm(target);
    default: throw Intern::InvalidTypeException();
    }
}

const char* Intern::InvalidTypeException::what() const throw() {
    return "Form name doesn't exist";
}
