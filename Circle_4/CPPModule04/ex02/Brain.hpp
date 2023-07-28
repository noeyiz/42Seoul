#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define RESET	"\033[0m"
# define GRAY	"\033[1;90m"

class Brain {
private:
    std::string ideas[100];

public:
    Brain(void);
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain(void);
};

#endif // BRAIN_HPP