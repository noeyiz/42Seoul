#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {
public:
    Weapon(void);
    Weapon(std::string type);
    const std::string& getType(void);
    void setType(std::string type);

private:
    std::string type;
};

#endif // WEAPON_HPP