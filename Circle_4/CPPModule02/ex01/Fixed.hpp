#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define CYAN		"\033[1;96m"
# define RESET		"\033[0m"

class Fixed {
private:
    int              value;
    static const int fractional_bits = 8;

public:
    Fixed( void );
    Fixed( const int value );
    Fixed( const float value );
    Fixed( const Fixed& other );
    ~Fixed( void );

    Fixed& operator=( const Fixed& other );

    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed );

#endif