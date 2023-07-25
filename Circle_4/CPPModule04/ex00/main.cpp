#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void check_leak(void) {
    system("leaks ex00 | grep leaked");
}

int main(void)
{
    atexit(check_leak);

    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "dog type : " << dog->getType() << std::endl;
    std::cout << "cat type : " << cat->getType() << std::endl;
    cat->makeSound(); // will output the cat sound!
    dog->makeSound();
    animal->makeSound();
    
    delete animal;
    delete dog;
    delete cat;

    /* test */
    std::cout << std::endl;
    const WrongAnimal* wrong_animal = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();

    std::cout << "wrong_cat type : " << wrong_cat->getType() << std::endl;
    wrong_cat->makeSound();
    wrong_animal->makeSound();

    delete wrong_animal;
    delete wrong_cat;

    return 0;
}