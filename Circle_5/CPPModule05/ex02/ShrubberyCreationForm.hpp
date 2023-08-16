#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>

# include "AForm.hpp"

// Required grades: sign 145, exec 137
class ShrubberyCreationForm : public AForm {
private:
    std::string target;

    void shrubbery(std::ofstream& ofs) const;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    virtual ~ShrubberyCreationForm();

    virtual void execute(Bureaucrat const & executor) const;
};

#endif // SHRUBBERYCREATIONFORM_HPP