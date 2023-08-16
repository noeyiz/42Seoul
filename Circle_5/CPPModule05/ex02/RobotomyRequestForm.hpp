#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include <ctime>

# include "AForm.hpp"

// Required grades: sign 72, exec 45
class RobotomyRequestForm : public AForm {
private:
    std::string target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm();

    virtual void execute(Bureaucrat const & executor) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP