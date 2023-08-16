#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), target("home") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        target = other.target;
        setSign(other.isSigned());
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::shrubbery(std::ofstream& ofs) const {
    ofs << "      *      " << std::endl;
    ofs << "     ***     " << std::endl;
    ofs << "    **o**    " << std::endl;
    ofs << "   *o*****   " << std::endl;
    ofs << "  *****o***  " << std::endl;
    ofs << " **o*****o** " << std::endl;
    ofs << "*************" << std::endl;
    ofs << "     |||     ";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
    if (isSigned() == false) throw AForm::FormNotSignedException();
    else if (executor.getGrade() > getExecGrade()) throw AForm::GradeTooLowException();
    
    std::string filename = target + "_shrubbery";
    std::ofstream ofs(filename.c_str());
    if (ofs.fail()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }
    shrubbery(ofs);
    ofs.close();
}
