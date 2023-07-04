#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define RESET		"\033[0m"
# define RED		"\033[1;91m"
# define YELLOW		"\033[1;93m"
# define MAGENTA	"\033[1;95m"
# define CYAN		"\033[1;96m"

class Harl {
public:
    Harl();
    void complain(std::string level);

private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    
    void (Harl::*funcs[4])(void);

    std::string levels[4];
};

#endif // HARL_HPP