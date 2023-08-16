#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), target("sinner") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        target = other.target;
        setSign(other.isSigned());
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (isSigned() == false) throw AForm::FormNotSignedException();
    else if (executor.getGrade() > getExecGrade()) throw AForm::GradeTooLowException();

    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
