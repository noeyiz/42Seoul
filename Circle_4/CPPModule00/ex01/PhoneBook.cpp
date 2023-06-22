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

void PhoneBook::add(void) {
    if (m_num_of_contacts < 8) m_num_of_contacts++;
    m_last_contact_idx = (m_last_contact_idx + 1) % 8;

    std::cout << MAGENTA << "\n연락처 정보를 하나씩 입력하세요" << RESET << std::endl;
    m_contacts[m_last_contact_idx].SetIndex(m_last_contact_idx);
    m_contacts[m_last_contact_idx].SetFirstName(getAddInput("FIRST NAME"));
    m_contacts[m_last_contact_idx].SetLastName(getAddInput("LAST NAME"));
    m_contacts[m_last_contact_idx].SetNickname(getAddInput("NICKNAME"));
    m_contacts[m_last_contact_idx].SetPhoneNumber(getAddInput("PHONE NUMBER"));
    m_contacts[m_last_contact_idx].SetDarkestSecret(getAddInput("DARKEST SECRET"));
    std::cout << MAGENTA << "• • • 전화번호 추가가 완료되었습니다\n" << RESET << std::endl;
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
            clearerr(stdin); // why ... :) eofbit failbit ?
            std::cin.clear();
            std::cout << std::endl;
        }
        std::cout << YELLOW << "올바른 범위가 아닙니다 다시 입력해주세요" << RESET << std::endl;
    }
}
