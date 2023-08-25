#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string db_file, std::string input_file)
: db_file(db_file), input_file(input_file) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
: db_file(other.db_file), input_file(other.input_file) {}

BitcoinExchange& BitcoinExchange::BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        db_file = other.db_file;
        input_file = other.input_file;
    }
    return *this;
}

void BitcoinExchange::parseDatabaseToMap() {
    std::ifstream ifs(db_file);
    if (ifs.fail()) throw FileOpenExcepton();

    std::string line, date, value;
    int seperate_idx;
    std::getline(ifs, line);
    while (getline(ifs, line)) {
        seperate_idx = line.find(',');
        date = line.substr(0, seperate_idx);
        value = line.substr(seperate_idx + 1);
        std::cout << "[" << date << ":" << value << "]";
    }
    ifs.close();
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::run() {
    try {
        parseDatabaseToMap();
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

const char* BitcoinExchange::FileOpenExcepton::what() const throw() {
    return "could not open file.";
}