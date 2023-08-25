#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <map>
# include <iostream>
# include <string>

class BitcoinExchange {
private:
    std::map<std::string, float> map;
    std::string db_file;
    std::string input_file;

    BitcoinExchange();

    void parseDatabaseToMap();

public:
    BitcoinExchange(std::string db_file, std::string input_file);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void run();

    class FileOpenExcepton : public std::exception {
        virtual const char* what() const throw();
    };
};

#endif // BITCOINEXCHANGE_HPP