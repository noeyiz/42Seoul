#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "Brain.hpp"
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
private:
    Brain *brain;

public:
    WrongCat(void);
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat(void);

    void makeSound(void) const;
};

#endif // WRONGCAT_HPP