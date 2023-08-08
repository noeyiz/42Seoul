#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "Floor.hpp"
# include "ICharacter.hpp"

# define SLOT_SIZE 4

class Character : public ICharacter {
private:
    std::string name;
    AMateria *slot[SLOT_SIZE];
    Floor floor;

public:
    Character(void);
    Character(std::string name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character(void);

    virtual std::string const & getName(void) const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

#endif // CHARACTER_HPP