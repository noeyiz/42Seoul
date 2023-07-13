#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
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
private:
    int              raw_bits;
    static const int fractional_bits = 8;

public:
    Fixed( void );
    Fixed( const int raw );
    Fixed( const float raw );
    Fixed( const Fixed& other );
    Fixed& operator=( const Fixed& other );
    ~Fixed( void );
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;

    bool operator>( const Fixed& other );
    bool operator<( const Fixed& other );
    bool operator>=( const Fixed& other );
    bool operator<=( const Fixed& other );
    bool operator==( const Fixed& other );
    bool operator!=( const Fixed& other );

    Fixed& operator+( const Fixed& other );
    Fixed& operator-( const Fixed& other );
    Fixed& operator*( const Fixed& other );
    Fixed& operator/( const Fixed& other );

    Fixed& operator++( void );
    Fixed operator++( int );
    Fixed& operator--( void );
    Fixed operator--( int );

    static Fixed& min( Fixed& one, Fixed &other );
    static const Fixed& min( const Fixed& one, const Fixed &other );
    static Fixed& max( Fixed& one, Fixed &other );
    static const Fixed& max( const Fixed& one, const Fixed &other );
};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed );

#endif // FIXED_HPP
