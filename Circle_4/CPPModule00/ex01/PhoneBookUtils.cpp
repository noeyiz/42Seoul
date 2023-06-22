#include "PhoneBook.hpp"

bool PhoneBook::isEmptyString(std::string str) {
    int size = str.size();

    for (int i = 0; i < size; i++) {
        if (isspace(str[i]) == false)
            return false;
    }

    return true;
}

std::string PhoneBook::getAddInput(std::string message) {
    std::string input;

    while (true) {
        std::cout << message << " : ";
        if (std::getline(std::cin, input) && isEmptyString(input) == false)
            break;
        if (std::cin.eof()) {
            clearerr(stdin); // why ... :) eofbit failbit ?
            std::cin.clear();
            std::cout << std::endl;
        }
        std::cout << YELLOW << "빈 문자는 올 수 없습니다 다시 입력해주세요" << RESET << std::endl;
    }

    return input;
}

void PhoneBook::printColumn(std::string str) {
    std::cout << "|";
    if (str.size() > 10) {
        std::cout << str.substr(0, 9) << ".";
    } else {
        std::cout.width(10);
        std::cout << std::right << str;
    }
}

void PhoneBook::displaySavedContacts(void) {
    std::string strs[] = {
        "----------", 
        "INDEX", 
        "FIRST NAME", 
        "LAST NAME", 
        "NICKNAME"
    };

    for (int i = 0; i < 4; i++) printColumn(strs[0]);
    std::cout << "|" << std::endl;
    for (int i = 1; i < 5; i++) printColumn(strs[i]);
    std::cout << "|" << std::endl;
    for (int i = 0; i < 4; i++) printColumn(strs[0]);
    std::cout << "|" << std::endl;
    for (int i = 0; i < m_num_of_contacts; i++) {
        printColumn(std::to_string(m_contacts[i].GetIndex()));
        printColumn(m_contacts[i].GetFirstName());
        printColumn(m_contacts[i].GetLastName());
        printColumn(m_contacts[i].GetNickname());
        std::cout << "|" << std::endl;
    }
    for (int i = 0; i < 4; i++) printColumn(strs[0]);
    std::cout << "|" << std::endl;
}

bool PhoneBook::isRightSearchInput(std::string input) {
    int n_input = static_cast<int>(input[0] - '0');

    if (isdigit(input[0]) == false || input.size() != 1
        || n_input < 0 || n_input > 7
        || (m_num_of_contacts < 8 && n_input > m_last_contact_idx))
        return false;
        
    return true;
}

void PhoneBook::displayContact(int idx) {
    std::string fields[] = {
        "FIRST NAME", 
        "LAST NAME", 
        "NICKNAME", 
        "PHONE NUMBER", 
        "DARKEST SECRET"
    };
    std::string (Contact::*funcs[])(void) = {
        &Contact::GetFirstName, 
        &Contact::GetLastName, 
        &Contact::GetNickname, 
        &Contact::GetPhoneNumber, 
        &Contact::GetDarkestSecret
    };

    for (int i = 0; i < 5; i++) {
        std::cout.width(14);
        std::cout << std::left << fields[i];
        std::cout << " : " << (m_contacts[idx].*funcs[i])() << std::endl;
    }
}
