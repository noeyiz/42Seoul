#include "Cat.hpp"
#include "Dog.hpp"

void check_leak(void) {
    system("leaks ex02 | grep leaked");
}

int	main( void )
{
    atexit(check_leak);

	AAnimal *cat = new Cat();
	cat->makeSound();
	delete cat;

	AAnimal *dog = new Dog();
	dog->makeSound();
	delete dog;

	/* test */
	// AAnimal *animal = new AAnimal();
}