#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    m_num_of_contacts = 0;
    m_last_contact_idx = -1;
}

/*
프로그램 시작 시 전화번호부가 비어 있고 사용자에게 세 가지 명령 중 하나를 입력하라는 메시지가 표시됩니다.
프로그램은 추가, 검색 및 종료만 허용합니다.
명령이 올바르게 실행되면 프로그램은 다른 명령을 기다립니다. 사용자가 EXIT를 입력하면 중지됩니다.
*/
void PhoneBook::Run(void) {
    std::string input;

    while (true) {
        std::cout << BLUE << "ADD SEARCH EXIT 중 하나를 입력하세요" << RESET << std::endl;
        if (std::getline(std::cin, input) == NULL) break;

        if (input == "ADD") add();
        else if (input == "SEARCH") search();
        else if (input == "EXIT") break;
        else std::cout << BLUE << "잘못된 입력입니다. ";
    }
}

bool isEmptyString(std::string str) {
    int size = str.size();

    for (int i = 0; i < size; i++) {
        if (isspace(str[i]) == false)
            return false;
    }
    return true;
}

std::string func(std::string message) {
    std::string input;

    while (true) {
        std::cout << message << " : ";
        if (std::getline(std::cin, input) == NULL) {
            clearerr(stdin); // why ... :)
            std::cin.clear();
            std::cout << std::endl;
            continue;
        }
        if (isEmptyString(input))
            std::cout << YELLOW << "빈 문자는 올 수 없습니다 다시 입력해주세요" << RESET << std::endl;
        else
            break ;
    }
    return input;
}

/*
• 추가: 새 연락처 저장
    ◦ 사용자가 이 명령을 입력하면 새 연락처 정보를 한 번에 하나씩 입력하라는 메시지가 나타납니다. 모든 필드가 완료되면 연락처를 전화번호부에 추가합니다.
    ◦ 연락처 필드는 이름, 성, 별명, 전화 번호 및 가장 어두운 비밀입니다. 저장된 연락처에는 빈 필드가 있을 수 없습니다.
*/
void PhoneBook::add(void) {
    if (m_num_of_contacts < 8) m_num_of_contacts++;
    m_last_contact_idx = (m_last_contact_idx + 1) % 8;

    std::cout << GREEN << "\n연락처 정보를 하나씩 입력하세요" << RESET << std::endl;
    m_contacts[m_last_contact_idx].SetFirstName(func("FIRST NAME"));
    m_contacts[m_last_contact_idx].SetLastName(func("LAST NAME"));
    m_contacts[m_last_contact_idx].SetNickname(func("NICKNAME"));
    m_contacts[m_last_contact_idx].SetPhoneNumber(func("PHONE NUMBER"));
    m_contacts[m_last_contact_idx].SetDarkestSecret(func("DARKEST SECRET"));
    std::cout << GREEN << "• • • 전화번호 추가가 완료되었습니다\n" << RESET << std::endl;
}

/*
• 검색: 특정 연락처 표시
    ◦ 저장된 연락처를 인덱스, 이름, 성 및 별명의 4개 열 목록으로 표시합니다.
    ◦ 각 열은 너비가 10자여야 합니다. 파이프 문자('|')는 두 문자를 구분합니다. 텍스트가 오른쪽으로 정렬되어야 합니다. 텍스트가 열보다 길면 텍스트를 잘라내고 표시 가능한 마지막 문자를 점('.')으로 대체해야 합니다.
    ◦ 그런 다음 항목의 색인을 표시할 것인지 사용자에게 다시 묻습니다. 인덱스가 범위를 벗어나거나 잘못된 경우 관련 동작을 정의합니다. 그렇지 않으면 연락처 정보를 한 줄에 하나의 필드로 표시합니다.
*/
void PhoneBook::search(void) {
    std::cout << "SEARCH할 예정" << std::endl;
}
