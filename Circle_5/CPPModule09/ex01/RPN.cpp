#include "RPN.hpp"

std::stack<double> RPN::stack;

void RPN::setFirstOperand(const std::string& input) {
    if (input.size() < 5 || std::isdigit(input[0]) == false)
        throw RPNException();
    stack.push(static_cast<double>(input[0] - '0'));
}

void RPN::performOperation(const std::string& input) {
    double operand_1, operand_2;
    for (size_t idx = 1; idx < input.size(); idx++) {
        if (input[idx] == ' ') { // 공백 위치가 정상적이지 않으면 error
            if (idx % 2 == 0 || idx == input.size() - 1) throw RPNException();
        } else if (std::isdigit(input[idx])) { // 숫자면 push
            stack.push(static_cast<double>(input[idx] - '0'));
        } else if (stack.size() < 2) { // 피연산자가 없으면 error
            throw RPNException();
        } else { // 연산 !!!
            operand_2 = stack.top();
            stack.pop();
            operand_1 = stack.top();
            stack.pop();
            switch (input[idx]) {
            case '+':
                stack.push(operand_1 + operand_2);
                break;
            case '-':
                stack.push(operand_1 - operand_2);
                break;
            case '/':
                stack.push(operand_1 / operand_2);
                break;
            case '*':
                stack.push(operand_1 * operand_2);
                break;
            default: throw RPNException();
            }
        }
    }
}

void RPN::displayResult() {
    // 모든 연산이 끝난 후 스택에는 결과값 하나만 담겨있어야 함 !
    if (stack.size() == 1)
        std::cout << stack.top() << std::endl;
    else
        throw RPNException();
}

void RPN::calculate(const std::string& input) {
    try {
        setFirstOperand(input);
        performOperation(input);
        displayResult();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

const char* RPN::RPNException::what() const throw() {
    return "Error";
}
