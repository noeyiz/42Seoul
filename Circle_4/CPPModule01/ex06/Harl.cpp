#include "./Harl.hpp"

Harl::Harl() {
    this->levels[0] = "DEBUG";
    this->levels[1] = "INFO";
    this->levels[2] = "WARNING";
    this->levels[3] = "ERROR";
}

void Harl::debug(void) {
    std::cout << CYAN << "[DEBUG] " << RESET << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
        << "I really do!\n" << std::endl;
}

void Harl::info(void) {
    std::cout << MAGENTA << "[INFO] " << RESET << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money.\n"
        << "You didn’t put enough bacon in my burger!\n"
        << "If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void) {
    std::cout << YELLOW << "[WARNING] " << RESET << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.\n"
        << "I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void) {
    std::cout << RED << "[ERROR] " << RESET << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level) {
    int index = -1;
    for (int i = 0; i < 4; i++)
        if (levels[i] == level) index = i;

    switch (index) {
        case 0: debug();
        case 1: info();
        case 2: warning();
        case 3: error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
