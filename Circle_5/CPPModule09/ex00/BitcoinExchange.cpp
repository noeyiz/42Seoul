#include "BitcoinExchange.hpp"

std::string BitcoinExchange::data_file = "data.csv";
std::map<std::string, double> BitcoinExchange::map;

void BitcoinExchange::parseDataToMap() {
    std::ifstream ifs(data_file.c_str());
    if (ifs.fail()) throw FileOpenException();

    std::string line, date, value;
    int separate_idx;

    std::getline(ifs, line);
    while (std::getline(ifs, line)) {
        separate_idx = line.find(',');
        date = line.substr(0, separate_idx);
        value = line.substr(separate_idx + 1);
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

void BitcoinExchange::displayResult(const std::string& date, const std::string& value) {
    // check date
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        throw BadInputException();
    int year, month, day; char separator;
    std::istringstream date_ss(date);
    date_ss >> year >> separator >> month >> separator >> day;
    if (date_ss.eof() == false || isValidDate(year, month, day) == false)
        throw BadInputException();

    // check value
    double val;
    std::istringstream value_ss(value);
    value_ss >> val;
    if (value_ss.eof() == false) throw BadInputException();
    if (val < 0) throw NonPositiveValueException();
    if (val > 1000.0) throw ValueTooLargeException();

    // display !!!
    std::map<std::string, double>::iterator it = map.begin();
    while (it->first <= date) it++;
    if (it != map.begin()) it--;
    std::cout << date << " => " << value << " = " << val * it->second << std::endl;
}

void BitcoinExchange::outputCalculatedValues(const std::string& input_file) {
    std::ifstream ifs(input_file.c_str());
    if (ifs.fail()) throw FileOpenException();

    std::string line, date, value;
    int separate_idx;

    std::getline(ifs, line);
    while (std::getline(ifs, line)) { // 한 줄씩 결과값 출력
        try {
            separate_idx = line.find('|');
            date = line.substr(0, separate_idx - 1);
            value = line.substr(separate_idx + 2);
            displayResult(date, value);
        } catch (BadInputException& e) {
            std::cout << "Error: " << e.what() << " => " << line << std::endl;
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    ifs.close();
}

void BitcoinExchange::exchange(const std::string& input_file) {
    try {
        parseDataToMap();
        outputCalculatedValues(input_file);
    } catch (FileOpenException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

const char* BitcoinExchange::FileOpenException::what() const throw() {
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
