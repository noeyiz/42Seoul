#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define RESET		"\033[0m"
# define GRAY		"\033[1;90m"
# define RED		"\033[1;91m"
# define CYAN		"\033[1;96m"

class ClapTrap {
protected:
    std::string name;
    unsigned int hit_points;
    unsigned int energy_points;
    unsigned int attack_damage;

    int max_hit_points;
    int max_energy_points;

    void setLimitedHitPoints(int point);
    void setLimitedEnergyPoints(int point);
    bool isAnyPointsZero(unsigned int hit, unsigned int energy);
    void showPoints(void);

public:
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(
        std::string name, 
        unsigned int hit_points, 
        unsigned int energy_points, 
        unsigned int attack_damage, 
        int max_hit_points, 
        int max_energy_points)
    ;
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap(void);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP