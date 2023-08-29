#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string db_file, std::string input_file)
: db_file(db_file), input_file(input_file) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
: db_file(other.db_file), input_file(other.input_file) {
    std::map<std::string, double>::iterator it = other.map.begin();
    while (it != other.map.end()) {
        map[it->first] = it->second;
        it++;
    }
}

BitcoinExchange& BitcoinExchange::BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        db_file = other.db_file;
        input_file = other.input_file;

        map.clear();
        std::map<std::string, double>::iterator it = other.map.begin();
        while (it != other.map.end()) {
            map[it->first] = it->second;
            it++;
        }
    }
    return *this;
}

void BitcoinExchange::parseDataToMap() {
    std::ifstream ifs(db_file);
    if (ifs.fail()) throw FileOpenExcepton();

    std::string line, date, value;
    int seperate_idx;

    std::getline(ifs, line);
    while (getline(ifs, line)) {
        seperate_idx = line.find(',');
        date = line.substr(0, seperate_idx);
        value = line.substr(seperate_idx + 1);
        map[date] = std::atof(value.c_str());
    }
    ifs.close();
}

bool isValidDate(int year, int month, int day) {
    if (year < 1 || month < 1 || month > 12 || day < 1) return false;

    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) // 윤년
        days_in_month[2] = 29;
    
    return day <= days_in_month[month];
}

void BitcoinExchange::checkInput(const std::string& date, const std::string& value) {
    // check date
    int year, month, day;
    char seperator;
    std::istringstream date_ss(date);
    if (date.size() != 10 || date[4] != '-' || date[7] != '-'
    || (date_ss >> year >> seperator >> month >> seperator >> day) == false
    || isValidDate(year, month, day) == false)
        throw BadInputException();

    // check value
    double val;
    std::istringstream value_ss(value);
    if ((value_ss >> val) == false) throw BadInputException();
    if (val < 0) throw NonPositiveValueException();
    if (val > 1000.0) throw ValueTooLargeException();
}

void BitcoinExchange::printResult() {
    std::ifstream ifs(input_file);
    if (ifs.fail()) throw FileOpenExcepton();

    std::string line, date, value;
    int seperate_idx;

    std::getline(ifs, line);
    while (getline(ifs, line)) {
        try {
            // 1. date, value 유효한 값인지 확인
            seperate_idx = line.find('|');
            date = line.substr(0, seperate_idx - 1);
            value = line.substr(seperate_idx + 2);
            checkInput(date, value);
            // 2. 가장 가까운 하위 날짜 사용
            std::map<std::string, double>::iterator it = map.begin();
            while (it->first <= date) it++;
            // 3. 출력
            std::cout << date << " => " << value << " = "
            << std::atof(value.c_str()) * (--it)->second << std::endl;
        } catch (BadInputException& e) {
            std::cout << "Error: " << e.what() << " => " << line << std::endl;
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    ifs.close();
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::run() {
    try {
        parseDataToMap();
        printResult();
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

const char* BitcoinExchange::FileOpenExcepton::what() const throw() {
    return "could not open file.";
}

const char* BitcoinExchange::NonPositiveValueException::what() const throw() {
    return "not a positive number.";
}

const char* BitcoinExchange::BadInputException::what() const throw() {
    return "bad input";
}

const char* BitcoinExchange::ValueTooLargeException::what() const throw() {
    return "too large a number.";
}
