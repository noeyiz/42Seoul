#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cmath>
# include <iostream>

enum e_type {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_NONE
};

class ScalarConverter {
private:
    static std::string str;
    static e_type type;
    static bool is_literal;
    static char c;
    static int i;
    static float f;
    static double d;

    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    static bool isChar();
    static bool isInt();
    static bool isFloat();
    static bool isDouble();
    static void detectType();
    static bool isImpossible();
    static void printChar();
    static void printInt();
    static void printFloat();
    static void printDouble();
public:
    static void convert(const std::string& input);
};

#endif // SCALARCONVERTER_HPP