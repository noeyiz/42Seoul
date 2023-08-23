#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("(null)"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(validateGrade(grade)) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(validateGrade(other.grade)) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) grade = validateGrade(other.grade);
    return *this;
}

Bureaucrat::~Bureaucrat() {}

int Bureaucrat::validateGrade(int grade) {
    if (grade < 1) throw Bureaucrat::GradeTooHighException();
    else if (grade > 150) throw Bureaucrat::GradeTooLowException();
    return grade;
}

std::string Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::increaseGrade() {
    grade = validateGrade(grade - 1);
}

void Bureaucrat::decreaseGrade() {
    grade = validateGrade(grade + 1);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade Too Low";
}
