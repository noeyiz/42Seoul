#include <iomanip>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    m_num_of_contacts = 0;
    m_last_contact_idx = -1;
}

void PhoneBook::Run(void) {
    std::string input;

    while (true) {
        std::cout << BLUE << "ADD SEARCH EXIT 중 하나를 입력하세요" << RESET << std::endl;
        if (std::getline(std::cin, input) == false) break;

        if (input == "ADD") add();
        else if (input == "SEARCH") search();
        else if (input == "EXIT") break;
        else std::cout << BLUE << "잘못된 입력입니다. ";
    }
    std::cout << BLUE << "\n• • • 전화번호부 프로그램을 종료합니다 🙂" << RESET << std::endl;
}

static bool isEmptyString(std::string str) {
    int size = str.size();

    for (int i = 0; i < size; i++) {
        if (std::isspace(str[i]) == false)
            return false;
    }
    return true;
}

std::string PhoneBook::getAddInput(std::string message) {
    std::string input;

    while (true) {
        std::cout << std::setw(14) << std::left << message << " : ";
        if (std::getline(std::cin, input) && isEmptyString(input) == false)
            break;
        if (std::cin.eof()) {
            clearerr(stdin);
            std::cin.clear();
            std::cout << std::endl;
        }
        std::cout << YELLOW << "빈 문자는 올 수 없습니다 다시 입력해주세요" << RESET << std::endl;
    }
    return input;
}

void PhoneBook::add(void) {
    if (m_num_of_contacts < PHONEBOOK_SIZE) m_num_of_contacts++;
    m_last_contact_idx = (m_last_contact_idx + 1) % PHONEBOOK_SIZE;

    std::cout << MAGENTA << "\n연락처 정보를 하나씩 입력하세요" << RESET << std::endl;
    m_contacts[m_last_contact_idx].SetIndex(m_last_contact_idx);
    m_contacts[m_last_contact_idx].SetFirstName(getAddInput("FIRST NAME"));
    m_contacts[m_last_contact_idx].SetLastName(getAddInput("LAST NAME"));
    m_contacts[m_last_contact_idx].SetNickname(getAddInput("NICKNAME"));
    m_contacts[m_last_contact_idx].SetPhoneNumber(getAddInput("PHONE NUMBER"));
    m_contacts[m_last_contact_idx].SetDarkestSecret(getAddInput("DARKEST SECRET"));
    std::cout << MAGENTA << "• • • 전화번호 추가가 완료되었습니다\n" << RESET << std::endl;
}

void PhoneBook::printColumn(std::string str) {
    std::cout << "|";
    if (str.size() > COLUMN_MAX) {
        std::cout << str.substr(0, COLUMN_MAX - 1) << ".";
    } else {
        std::cout << std::setw(COLUMN_MAX) << std::right << str;
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

    if (std::isdigit(input[0]) == false || input.size() != 1
        || n_input < 0 || n_input > PHONEBOOK_SIZE - 1
        || (m_num_of_contacts < PHONEBOOK_SIZE && n_input > m_last_contact_idx))
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
        std::cout << std::setw(14) << std::left << fields[i];
        std::cout << " : " << (m_contacts[idx].*funcs[i])() << std::endl;
    }
}

void PhoneBook::search(void) {
    std::string input;

    std::cout << MAGENTA << std::endl;
    if (m_num_of_contacts == 0) {
        std::cout << "전화번호부가 비어있습니다\n" << RESET << std::endl;
        return;
    }
    displaySavedContacts();
    while (true) {
        std::cout << MAGENTA << "검색하고 싶은 전화번호의 인덱스를 입력하세요 : " << RESET;
        if (std::getline(std::cin, input) && isRightSearchInput(input)) {
            std::cout << MAGENTA << std::endl;
            displayContact(static_cast<int>(input[0] - '0'));
            std::cout << RESET << std::endl;
            break;
        }
        if (std::cin.eof()) {
            clearerr(stdin);
            std::cin.clear();
            std::cout << std::endl;
        }
        std::cout << YELLOW << "올바른 범위가 아닙니다 다시 입력해주세요" << RESET << std::endl;
    }
}
