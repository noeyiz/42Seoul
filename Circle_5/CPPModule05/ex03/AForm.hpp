#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

# include "Bureaucrat.hpp"

class AForm {
private:
    const std::string name;
    bool  is_signed;
    const int sign_grade;
    const int exec_grade;

protected:
    void setSign(bool is_signed);
    int validateGrade(int grade);

public:
    AForm();
    AForm(std::string name, int sign_grade, int exec_grade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    std::string getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;
    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif // AFORM_HPP