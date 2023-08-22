#include "AForm.hpp"

AForm::AForm() : name("(null)"), is_signed(false), sign_grade(150), exec_grade(150) {}

AForm::AForm(std::string name, int sign_grade, int exec_grade) :
    name(name),
    is_signed(false),
    sign_grade(validateGrade(sign_grade)),
    exec_grade(validateGrade(exec_grade)) {}

AForm::AForm(const AForm& other) : 
    name(other.name),
    is_signed(other.is_signed),
    sign_grade(validateGrade(other.sign_grade)),
    exec_grade(validateGrade(other.exec_grade)) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) is_signed = other.is_signed;
    return *this;
}

AForm::~AForm() {}

void AForm::setSign(bool is_signed) {
    this->is_signed = is_signed;
}

int AForm::validateGrade(int grade) {
    if (grade < 1) throw AForm::GradeTooHighException();
    else if (grade > 150) throw AForm::GradeTooLowException();
    return grade;
}

std::string AForm::getName() const {
    return name;
}

bool AForm::isSigned() const {
    return is_signed;
}

int AForm::getSignGrade() const {
    return sign_grade;
}

int AForm::getExecGrade() const {
    return exec_grade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    int grade = bureaucrat.getGrade();

    if (grade > sign_grade)
        throw AForm::GradeTooLowException();
    if (is_signed)
        std::cout << "( " << name << " is already signed )" << std::endl;
    is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade Too Low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form Not Signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << form.getName() << " can sign above grade " << form.getSignGrade()
        << " and execute above grade " << form.getExecGrade();
    return os;
}
