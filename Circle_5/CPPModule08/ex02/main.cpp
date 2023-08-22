#include <iostream>
#include <list>

#include "MutantStack.hpp"

// int main() {
//     MutantStack<int> mstack;

//     mstack.push(5);
//     mstack.push(17);

//     std::cout << mstack.top() << std::endl;

//     mstack.pop();

//     std::cout << mstack.size() << std::endl;

//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);

//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();

//     ++it;
//     --it;
//     while (it != ite) {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::stack<int> s(mstack);

//     return 0;
// }

int main() {
    // MutantStack 객체 생성
    MutantStack<int> stack;

    // 스택에 원소 추가
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    // 반복자를 사용하여 스택의 원소 출력
    std::cout << "Stack elements using iterator: ";
    for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 역순 반복자를 사용하여 스택의 원소 역순으로 출력
    std::cout << "Stack elements in reverse using reverse iterator: ";
    for (MutantStack<int>::reverse_iterator rit = stack.rbegin(); rit != stack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // 상수 반복자를 사용하여 스택의 원소 출력
    std::cout << "Stack elements using const iterator: ";
    for (MutantStack<int>::const_iterator cit = stack.cbegin(); cit != stack.cend(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    // 상수 역순 반복자를 사용하여 스택의 원소 역순으로 출력
    std::cout << "Stack elements in reverse using const reverse iterator: ";
    for (MutantStack<int>::const_reverse_iterator crit = stack.crbegin(); crit != stack.crend(); ++crit) {
        std::cout << *crit << " ";
    }
    std::cout << std::endl;

    return 0;
}