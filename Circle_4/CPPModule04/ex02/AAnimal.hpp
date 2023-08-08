#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define RESET		"\033[0m"
# define GRAY		"\033[1;90m"

class AAnimal {
protected:
    std::string type;

public:
    AAnimal(void);
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal(void);

    std::string getType(void) const;
    virtual void makeSound(void) const = 0;
};

#endif // ANIMAL_HPP