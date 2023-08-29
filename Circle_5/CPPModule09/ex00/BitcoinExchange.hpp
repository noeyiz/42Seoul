#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <map>
# include <iostream>
# include <sstream>
# include <string>

class BitcoinExchange {
private:
    std::map<std::string, double> map;
    std::string db_file;
    std::string input_file;

    BitcoinExchange();

    void parseDataToMap();
    void checkInput(const std::string& date, const std::string& value);
    void printResult();

public:
    BitcoinExchange(std::string db_file, std::string input_file);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void run();

    class FileOpenExcepton : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NonPositiveValueException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class BadInputException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class ValueTooLargeException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif // BITCOINEXCHANGE_HPP