#include "Cat.hpp"
#include "Dog.hpp"

void check_leak(void) {
    system("leaks ex01 | grep leaked");
}


int	main( void )
{
    atexit(check_leak);

    /* test */
	Animal	*animals[4];

	for (int i = 0; i < 4; i++) {
		if (i % 2) animals[i] = new Dog();
		else animals[i] = new Cat();
		std::cout << animals[i]->getType() << std::endl;
	}

	for (int i = 0; i < 4; i++)
		delete animals[i];
}