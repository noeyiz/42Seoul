#include "Cat.hpp"
#include "Dog.hpp"

void check_leak(void) {
    system("leaks ex02 | grep leaked");
}

int	main( void )
{
    atexit(check_leak);

	Animal *cat = new Cat();
	cat->makeSound();
	delete cat;

	Animal *dog = new Dog();
	dog->makeSound();
	delete dog;

	/* test */
	// Animal *animal = new Animal();
}