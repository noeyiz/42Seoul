#include "ScalarConverter.hpp"

e_type detectType(const std::string& input) {
    if (input.size() == 1 && std::isdigit(input[0]) == false)
        return TYPE_CHAR;
    if (input == "inff" || input == "+inff" || input == "-inff" || input == "nanf")
        return TYPE_FLOAT;
    if (input == "inf" || input == "+inf" || input == "-inf" || input == "nan")
        return TYPE_DOUBLE;
    
    size_t idx = 0;
    if (input[0] == '-' || input[0] == '+') idx++;
    bool dot_flag = false, f_flag = false;
    for (size_t i = idx; i < input.size(); i++) {
        if (std::isdigit(input[i]) == false) {
            if (input[i] == '.' && dot_flag == false && i != idx && i != input.size() - 1) dot_flag = true;
            else if (input[i] == 'f' && i == input.size() - 1 && dot_flag) f_flag = true;
            else return TYPE_NAN;
        }
    }

    if (dot_flag == false) return TYPE_INT;
    else if (f_flag) return TYPE_FLOAT;
    else return TYPE_DOUBLE;
}

char castToChar(const std::string& input, e_type type) {
    int i_val; float f_val; double d_val;

    switch (type) {
    case TYPE_CHAR:
        return input[0];
    case TYPE_INT:
        i_val = std::stoi(input);
        if (i_val < -128 || i_val > 127) throw std::exception();
        return static_cast<char>(i_val);
    case TYPE_FLOAT:
        f_val = std::stof(input);
        if (f_val < -128 || f_val > 127) throw std::exception();
        return static_cast<char>(f_val);
    case TYPE_DOUBLE:
        d_val = std::stod(input);
        if (d_val < -128 || d_val > 127) throw std::exception();
        return static_cast<char>(d_val);
    default:
        throw std::exception();
    }
}

int castToInt(const std::string& input, e_type type) {
    float f_val; double d_val;

    switch (type) {
    case TYPE_CHAR:
        return static_cast<int>(input[0]);
    case TYPE_INT:
        return std::stoi(input);
    case TYPE_FLOAT:
        f_val = std::stof(input);
        if (std::abs(f_val) == 1.0f / 0.0f) throw std::exception();
        std::stoi(input);
        return static_cast<int>(f_val);
    case TYPE_DOUBLE:
        d_val = std::stod(input);
        if (std::abs(d_val) == 1.0 / 0.0) throw std::exception();
        std::stoi(input);
        return static_cast<int>(d_val);
    default:
        throw std::exception();
    }
}

float castToFloat(const std::string& input, e_type type) {
    double d_val;

    switch (type) {
    case TYPE_CHAR:
        return static_cast<float>(input[0]);
    case TYPE_INT:
        return static_cast<float>(std::stoi(input));
    case TYPE_FLOAT:
        return std::stof(input);
    case TYPE_DOUBLE:
        d_val = std::stod(input);
        std::stof(input);
        return static_cast<float>(d_val);
    default:
        throw std::exception();
    }
}

double castToDouble(const std::string& input, e_type type) {
    switch (type) {
    case TYPE_CHAR:
        return static_cast<double>(input[0]);
    case TYPE_INT:
        return static_cast<double>(std::stoi(input));
    case TYPE_FLOAT:
        return static_cast<double>(std::stof(input));
    case TYPE_DOUBLE:
        return std::stod(input);
    default:
        throw std::exception();
    }
}


void ScalarConverter::convert(const std::string& input) {
    e_type type = detectType(input);

    std::cout << "char: ";
    try {
        char c = castToChar(input, type);
        if (std::isprint(c)) std::cout << c << std::endl;
        else std::cout << "non displayable" << std::endl;
    } catch (std::exception &) {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "int: ";
    try {
        std::cout << castToInt(input, type) << std::endl;
    } catch (std::exception &) {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "float: ";
    try {
        float f = castToFloat(input, type);
        std::cout << f;
        if (f == std::floorf(f) && f < std::powf(10.f, 6.f)) std::cout << ".0";
        std::cout << "f" << std::endl;
    } catch (std::exception &) {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "double: ";
    try {
        double d = castToDouble(input, type);
        std::cout << d;
        if (d == std::floor(d) && d < std::pow(10.0, 6.0)) std::cout << ".0";
        std::cout << std::endl;
    } catch (std::exception &) {
        std::cout << "impossible" << std::endl;
    }
}

    // std::cout << "type : ";
    // switch(type) {
    // case TYPE_CHAR: std::cout << "CHAR"; break;
    // case TYPE_INT: std::cout << "INT"; break;
    // case TYPE_FLOAT: std::cout << "FLOAT"; break;
    // case TYPE_DOUBLE: std::cout << "DOUBLE"; break;
    // case TYPE_NAN: std::cout << "NAN"; break;
    // }
    // std::cout << std::endl;