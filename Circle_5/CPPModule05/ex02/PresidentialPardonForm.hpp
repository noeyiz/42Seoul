#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

//  Required grades: sign 25, exec 5
class PresidentialPardonForm : public AForm {
private:
    std::string target;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    virtual ~PresidentialPardonForm();

    virtual void execute(Bureaucrat const & executor) const;
};

#endif // PRESIDENTIALPARDONFORM_HPP