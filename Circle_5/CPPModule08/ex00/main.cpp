#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

template <typename T>
void print(T& container, std::string name) {
    std::cout << name << " = {";
    for (typename T::iterator it = container.begin(); it != container.end(); it++) {
        std::cout << *it;
        if (it != --(container.end())) std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}

template <typename T>
void print(const T& container, std::string name) {
    std::cout << name << " = {";
    for (typename T::const_iterator it = container.begin(); it != container.end(); it++) {
        std::cout << *it;
        if (it != --(container.end())) std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}

template <typename T>
void printEasyFind(T& container, int target) {
    typename T::iterator it = easyfind(container, target);

    std::cout << "easyfind(" << target << ") : ";
    if (it != container.end()) {
        std::cout << *it;
        if (++it != container.end()) std::cout << " (next is " << *it << ")";
    } else {
        std::cout << "can't find !!! 🙁";
    }
    std::cout << std::endl;
}

template <typename T>
void printEasyFind(const T& container, int target) {
    typename T::const_iterator it = easyfind(container, target);

    std::cout << "easyfind(" << target << ") : ";
    if (it != container.end()) {
        std::cout << *it;
        if (++it != container.end()) std::cout << " (next is " << *it << ")";
    } else {
        std::cout << "can't find !!! 🙁";
    }
    std::cout << std::endl;
}

int main() {
    std::deque<int> deque;
    std::list<int> list;
    std::vector<int> vector;
    for (int i = 0; i < 5; i++) {
        deque.push_back(i + 1);
        list.push_back(i + 1);
        vector.push_back(i + 1);
    }
    const std::vector<int> v(vector);


    // 예시 1) deque
    print(deque, "deque");
    printEasyFind(deque, 2);

    std::cout << std::endl;

    // 예시 2) list
    list.push_back(5);
    print(list, "list");
    printEasyFind(list, 5);

    std::cout << std::endl;

    // 예시 3) vector
    print(vector, "vector");
    printEasyFind(vector, 100);

    std::cout << std::endl;

    // 예시 4) const vector
    print(v, "const vector");
    printEasyFind(v, 5);
    
    return 0;
}