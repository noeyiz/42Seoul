#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        BitcoinExchange bitcoinExchange("data.csv", argv[1]);
        bitcoinExchange.run();
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}