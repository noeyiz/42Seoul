#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define RESET		"\033[0m"
# define GRAY		"\033[1;90m"
# define RED		"\033[1;91m"
# define GREEN		"\033[1;92m"
# define YELLOW		"\033[1;93m"
# define BLUE		"\033[1;94m"
# define MAGENTA	"\033[1;95m"
# define CYAN		"\033[1;96m"

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