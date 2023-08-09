#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// void check_leak(void) {
//     system("leaks ex01 | grep leaked");
// }

int	main( void )
{
    // atexit(check_leak);

	Animal	*animals[4];

	for (int i = 0; i < 4; i++) {
		if (i % 2) animals[i] = new Dog();
		else animals[i] = new Cat();
		std::cout << animals[i]->getType() << std::endl;
	}

	for (int i = 0; i < 4; i++)
		delete animals[i];
	
    /* test */
	// std::cout << std::endl;
	// WrongAnimal *wrong_animals[4];

	// for (int i = 0; i < 4; i++) {
	// 	wrong_animals[i] = new WrongCat();
	// 	std::cout << wrong_animals[i]->getType() << std::endl;
	// }

	// for (int i = 0; i < 4; i++)
	// 	delete wrong_animals[i];
}