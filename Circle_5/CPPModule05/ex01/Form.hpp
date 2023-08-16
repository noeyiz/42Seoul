#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form {
private:
    const std::string name;
    bool  is_signed;
    const int sign_grade;
    const int exec_grade;

    int validateGrade(int grade);

public:
    Form();
    Form(std::string name, int sign_grade, int exec_grade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    std::string getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;
    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // FORM_HPP