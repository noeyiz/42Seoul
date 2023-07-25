#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
private:
    Brain* brain;

public:
    Cat(void);
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat(void);

    virtual void makeSound(void) const;
};

#endif // CAT_HPP