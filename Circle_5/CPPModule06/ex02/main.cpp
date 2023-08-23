#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
    srand(static_cast<unsigned int>(time(NULL)));
    int rand_num = rand() % 3;

    switch (rand_num) {
    case 0:
        return new A();
    case 1:
        return new B();
    default:
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "identify(*) : A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "identify(*) : B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "identify(*) : C" << std::endl;
    }
}

void identify(Base& p) {
    try {
        A a = dynamic_cast<A&>(p);
        std::cout << "identify(&) : A" << std::endl;
    } catch (std::exception &) {}

    try {
        B b = dynamic_cast<B&>(p);
        std::cout << "identify(&) : B" << std::endl;
    } catch (std::exception &) {}

    try {
        C c = dynamic_cast<C&>(p);
        std::cout << "identify(&) : C" << std::endl;
    } catch (std::exception &) {}
}

int main() {
    Base *base = generate();
    identify(base);
    identify(*base);

    return 0;
}