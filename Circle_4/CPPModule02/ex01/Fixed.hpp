#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
public:
    Fixed();
    Fixed(const int number);
    Fixed(const float number);
    Fixed(const Fixed& other);
    ~Fixed();

    Fixed& operator=(const Fixed& other);
    std::ostream& operator<<(std::ostream& os);

    float toFloat(void) const;
    int toInt(void) const;

private:
    float number;
    static const int fractional_bits = 8;
};

#endif