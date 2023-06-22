#include "Contact.hpp"

int Contact::GetIndex(void) {
    return m_index;
}

std::string Contact::GetFirstName(void) {
    return m_first_name;
}

std::string Contact::GetLastName(void) {
    return m_last_name;
}

std::string Contact::GetNickname(void) {
    return m_nickname;
}

std::string Contact::GetPhoneNumber(void) {
    return m_phone_number;
}

std::string Contact::GetDarkestSecret(void) {
    return m_darkest_secret;
}

void Contact::SetIndex(int index) {
    m_index = index;
}

void Contact::SetFirstName(std::string first_name) {
    m_first_name = first_name;
}

void Contact::SetLastName(std::string last_name) {
    m_last_name = last_name;
}

void Contact::SetNickname(std::string nickname) {
    m_nickname = nickname;
}

void Contact::SetPhoneNumber(std::string phone_number) {
    m_phone_number = phone_number;
}

void Contact::SetDarkestSecret(std::string darkest_secret) {
    m_darkest_secret = darkest_secret;
}
