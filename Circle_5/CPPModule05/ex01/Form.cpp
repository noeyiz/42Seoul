#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("(null)"), is_signed(false), sign_grade(150), exec_grade(150) {}

Form::Form(std::string name, int sign_grade, int exec_grade) :
    name(name),
    is_signed(false),
    sign_grade(validateGrade(sign_grade)),
    exec_grade(validateGrade(exec_grade)) {}

Form::Form(const Form& other) : 
    name(other.name),
    is_signed(other.is_signed),
    sign_grade(validateGrade(other.sign_grade)),
    exec_grade(validateGrade(other.exec_grade)) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) is_signed = other.is_signed;
    return *this;
}

Form::~Form() {}

int Form::validateGrade(int grade) {
    if (grade < 1) throw Form::GradeTooHighException();
    else if (grade > 150) throw Form::GradeTooLowException();
    return grade;
}

std::string Form::getName() const {
    return name;
}

bool Form::isSigned() const {
    return is_signed;
}

int Form::getSignGrade() const {
    return sign_grade;
}

int Form::getExecGrade() const {
    return exec_grade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    int grade = bureaucrat.getGrade();

    if (grade > sign_grade)
        throw Form::GradeTooLowException();
    is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade Too Low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName() << " can sign above grade " << form.getSignGrade()
        << " and execute above grade " << form.getExecGrade();
    return os;
}
