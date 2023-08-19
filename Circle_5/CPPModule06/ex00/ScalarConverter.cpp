#include "ScalarConverter.hpp"

bool isChar(const std::string& str) {
    return str.size() == 1 && (std::isalpha(str[0]) || std::isprint(str[0]));
}

bool isInt(const std::string& str) {
    int idx = 0;
    if (str[idx] == '-' || str[idx] == '+') idx++;
    // 숫자가 아닌 문자가 있으면 false
    for (unsigned long i = idx; i < str.size(); i++)
        if (std::isdigit(str[i]) == false) return false;
    return true;
}

bool isFloat(const std::string& str) {
    // f, .이 없거나 .의 위치가 맨앞 또는 맨뒤면 false
    if (str.back() != 'f' 
    || str.find('.') == std::string::npos
    || str.find('.') == 0
    || str.find('.') == str.size() - 2)
        return false;

    int idx = 0;
    if (str[idx] == '-' || str[idx] == '+') idx++;
    // f 전까지 확인, .이 아닌 다른 문자가 오거나 이미 .이 두번 이상 나온 경우
    int dot = 0;
    for (unsigned long i = idx; i < str.size() - 1; i++) {
        if (str[i] == '.') dot++;
        if ((std::isdigit(str[i]) == false && str[i] != '.') || dot > 1)
            return false;
    }
    return true;
}

bool isDouble(const std::string& str) {
    // .이 없거나 .의 위치가 맨앞 또는 맨뒤면 false
    if (str.find('.') == std::string::npos
    || str.find('.') == 0
    || str.find('.') == str.size() - 1)
        return false;
    
    int idx = 0;
    if (str[idx] == '-' || str[idx] == '+') idx++;
    // .이 아닌 다른 문자가 오거나 이미 .이 두번 이상 나온 경우
    int dot = 0;
    for (unsigned long i = idx; i < str.size(); i++) {
        if (str[i] == '.') dot++;
        if ((std::isdigit(str[i]) == false && str[i] != '.') || dot > 1)
            return false;
    }
    return true;
}

bool isOther(const std::string& str) {
    return (str == "inff" || str == "-inff" || str == "+inff" || str == "nanf"
        || str == "inf" || str == "-inf" || str == "+inf" || str == "nan");
}

e_type getType(const std::string& str) {
    if (isChar(str)) return CHAR;
    else if (isInt(str)) return INT;
    else if (isFloat(str)) return FLOAT;
    else if (isDouble(str)) return DOUBLE;
    else if (isOther(str)) return OTHER;
    else return NONE;
}

void ScalarConverter::convert(const std::string& input) {
    e_type type = getType(input);
    char c;
    int i;
    float f;
    double d;
}