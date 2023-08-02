#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "Floor.hpp"
# include "ICharacter.hpp"

# define RESET		"\033[0m"
# define GRAY		"\033[1;90m"
# define RED		"\033[1;91m"
# define GREEN		"\033[1;92m"
# define YELLOW		"\033[1;93m"
# define BLUE		"\033[1;94m"
# define MAGENTA	"\033[1;95m"
# define CYAN		"\033[1;96m"

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
    ~Character(void);

    virtual std::string const & getName(void) const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

#endif // CHARACTER_HPP