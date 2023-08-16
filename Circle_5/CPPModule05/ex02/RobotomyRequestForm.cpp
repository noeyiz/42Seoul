#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), target("Taekwon-V") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        target = other.target;
        setSign(other.isSigned());
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (isSigned() == false) throw AForm::FormNotSignedException();
    else if (executor.getGrade() > getExecGrade()) throw AForm::GradeTooLowException();

    std::cout << "💥 drilling ~~~ ..." << std::endl;

    // 시드값 설정 (현재 시간 사용)
    srand(static_cast<unsigned int>(time(NULL)));
    if (rand() % 2) {
        std::cout << target << " has been robotomized successfully !!!🤖" << std::endl;
    } else {
        std::cout << target << " hasn't been robotomized ..." << std::endl;
    }
}
