#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

enum e_type {
    NONE,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    OTHER
};

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

public:
    static void convert(const std::string& input);
};

#endif // SCALARCONVERTER_HPP