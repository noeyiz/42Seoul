#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define RESET		"\033[0m"
# define GRAY		"\033[1;90m"
# define RED		"\033[1;91m"
# define GREEN		"\033[1;92m"
# define YELLOW		"\033[1;93m"
# define BLUE		"\033[1;94m"
# define MAGENTA	"\033[1;95m"
# define CYAN		"\033[1;96m"

class ClapTrap {
protected:
    std::string name;
    unsigned int hit_points;
    unsigned int energy_points;
    unsigned int attack_damage;
    const int initial_hit_points;
    const int initial_energy_points;

    bool isAnyPointsZero();
    void showPoints();
    void setLimitedHitPoints(int point);
    void setLimitedEnergyPoints(int point);

public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(std::string name, unsigned int his_points, unsigned int energy_points, unsigned int attack_damage);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP