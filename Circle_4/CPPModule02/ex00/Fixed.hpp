#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define RESET		"\033[0m"
# define GRAY		"\033[1;90m"
# define RED		"\033[1;91m"
# define GREEN		"\033[1;92m"
# define YELLOW		"\033[1;93m"
# define BLUE		"\033[1;94m"
# define MAGENTA	"\033[1;95m"
# define CYAN		"\033[1;96m"

class Fixed {
public:
    Fixed();
    Fixed(const Fixed& other);
    ~Fixed();

    Fixed& operator=(const Fixed& other);
    
    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int number;
    static const int fractional_bits = 8;
};

#endif // FIXED_HPP