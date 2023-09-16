#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN {
private:
    static std::stack<double> stack;

    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    static void setFirstOperand(const std::string& input);
    static void performOperation(const std::string& input);
    static void displayResult();

public:
    static void calculate(const std::string& input);

    class RPNException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif // RPN_HPP