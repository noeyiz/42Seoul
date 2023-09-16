#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cstdlib>
# include <fstream>
# include <iostream>
# include <map>
# include <sstream>

class BitcoinExchange {
private:
    static std::string data_file;
    static std::map<std::string, double> map;

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    static void parseDataToMap();
    static void outputCalculatedValues(const std::string& input_file);
    static void displayResult(const std::string& date, const std::string& value);

public:
    static void exchange(const std::string& input_file);

    class FileOpenException : public std::exception {
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