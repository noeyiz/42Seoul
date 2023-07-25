#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
public:
    Dog(void);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog(void);

    virtual void makeSound(void) const;
};

#endif // DOG_HPP