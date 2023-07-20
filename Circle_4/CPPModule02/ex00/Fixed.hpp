#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
private:
    int              value;
    static const int bits = 8;

public:
    Fixed(void);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed(void);
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif // FIXED_HPP