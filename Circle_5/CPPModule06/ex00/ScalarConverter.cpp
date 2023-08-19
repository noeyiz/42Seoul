#include "ScalarConverter.hpp"

std::string ScalarConverter::str = "";
e_type ScalarConverter::type = TYPE_NONE;
bool ScalarConverter::is_literal = false;
char ScalarConverter::c = '\0';
int ScalarConverter::i = 0;
float ScalarConverter::f = 0.0f;
double ScalarConverter::d = 0.0;

bool ScalarConverter::isChar() {
    return str.size() == 1 && std::isdigit(str[0]) == false;
}

bool ScalarConverter::isInt() {
    int idx = 0;
    if (str[0] == '-' || str[0] == '+') idx++;

    // 숫자가 아닌 문자가 있다면 false
    for (unsigned long i = idx; i < str.size(); i++) {
        if (std::isdigit(str[i]) == false)
            return false;
    }

    return true;
}

bool ScalarConverter::isFloat() {
    if (str == "inff" || str == "-inff" || str == "+inff" || str == "nanf") {
        is_literal = true;
        return true;
    }

    // 'f'로 끝나지 않거나 '.'의 위치가 정상적이지 않으면 false
    if (str.back() != 'f' || str.find('.') == std::string::npos
        || str.find('.') == 0 || str.find('.') == str.size() - 2)
        return false;

    int idx = 0, dot = 0;
    if (str[0] == '-' || str[0] == '+') idx++;
    // 숫자가 아닌 다른 문자가 있거나 '.'이 두번 이상 나오면 false
    for (unsigned long i = idx; i < str.size() - 1; i++) {
        if (str[i] == '.') dot++;
        if ((std::isdigit(str[i]) == false && str[i] != '.') || dot > 1)
            return false;
    }

    return true;
}

bool ScalarConverter::isDouble() {
    if (str == "inf" || str == "-inf" || str == "+inf" || str == "nan") {
        is_literal = true;
        return true;
    }

    // '.'의 위치가 정상적이지 않으면 false
    if (str.find('.') == std::string::npos
        || str.find('.') == 0 || str.find('.') == str.size() - 1)
        return false;

    int idx = 0, dot = 0;
    if (str[0] == '-' || str[0] == '+') idx++;
    // 숫자가 아닌 다른 문자가 있거나 '.'이 두번 이상 나오면 false
    for (unsigned long i = idx; i < str.size(); i++) {
        if (str[i] == '.') dot++;
        if ((std::isdigit(str[i]) == false && str[i] != '.') || dot > 1)
            return false;
    }

    return true;
}

void ScalarConverter::detectType() {
    if (isChar()) type = TYPE_CHAR;
    else if (isInt()) type = TYPE_INT;
    else if (isFloat()) type = TYPE_FLOAT;
    else if (isDouble()) type = TYPE_DOUBLE;
    else type = TYPE_NONE;
}

bool ScalarConverter::isImpossible() {
    try {
        if (type == TYPE_INT) std::stoi(str);
        else if (type == TYPE_FLOAT) std::stof(str);
        else if (type == TYPE_DOUBLE) std::stod(str);
    } catch (std::out_of_range& e) {
        return true;
    }
    return false;
}

void ScalarConverter::printChar() {
    std::cout << "char : ";

    if (type == TYPE_NONE || is_literal) std::cout << "Impossible";
    else if (std::isprint(c)) std::cout << "'" << c << "'" ;
    else std::cout << "Non displayable";

    std::cout << std::endl;
}

void ScalarConverter::printInt() {
    std::cout << "int : ";

    if (type == TYPE_NONE || is_literal) std::cout << "Impossible";
    else std::cout << i;

    std::cout << std::endl;
}

void ScalarConverter::printFloat() {
    std::cout << "float : ";

    if (type == TYPE_NONE) std::cout << "Impossible";
    else if (str == "inff" || str == "inf") std::cout << "inff";
    else if (str == "+inff" || str == "+inf") std::cout << "+inff";
    else if (str == "-inff" || str == "-inf") std::cout << "-inff";
    else if (str == "nanf" || str == "nan") std::cout << "nanf";
    else if (f == std::floor(f)) std::cout << f << ".0f";
    else std::cout << f << "f";

    std::cout << std::endl;
}

void ScalarConverter::printDouble() {
    std::cout << "double : ";

    if (type == TYPE_NONE) std::cout << "Impossible";
    else if (str == "inff" || str == "inf") std::cout << "inf";
    else if (str == "+inff" || str == "+inf") std::cout << "+inf";
    else if (str == "-inff" || str == "-inf") std::cout << "-inf";
    else if (str == "nanf" || str == "nan") std::cout << "nan";
    else if (d == std::floor(d)) std::cout << d << ".0";
    else std::cout << d;

    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& input) {
    str = input;
    detectType();
    // 변환 불가능
    if (isImpossible()) type = TYPE_NONE;

    // 변환 !!!
    switch(type) {
    case TYPE_CHAR:
        c = str[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
        break;
    case TYPE_INT:
        i = std::stoi(str);
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        break;
    case TYPE_FLOAT:
        f = std::stof(str);
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
        break;
    case TYPE_DOUBLE:
        d = std::stod(str);
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
        break;
    default: break;
    }

    printChar();
    printInt();
    printFloat();
    printDouble();
}