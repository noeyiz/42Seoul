#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define RESET	"\033[0m"
# define RED	    "\033[1;91m"

class Bureaucrat {
private:
    const std::string name;
    int grade;

    int validateGrade(int grade);

public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void increaseGrade();
    void decreaseGrade();

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_HPP