#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void check_leak(void) {
    system("leaks ex02 | grep leaked");
}

int	main( void )
{
    atexit(check_leak);

	Animal	*animals[4];

	for (int i = 0; i < 4; i++) {
		if (i % 2) animals[i] = new Dog();
		else animals[i] = new Cat();
		std::cout << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}

	for (int i = 0; i < 4; i++)
		delete animals[i];
}