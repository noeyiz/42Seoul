#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
public:
    int         GetIndex(void);
    std::string GetFirstName(void);
    std::string GetLastName(void);
    std::string GetNickname(void);
    std::string GetPhoneNumber(void);
    std::string GetDarkestSecret(void);
    void        SetIndex(int index);
    void        SetFirstName(std::string first_name);
    void        SetLastName(std::string last_name);
    void        SetNickname(std::string nickname);
    void        SetPhoneNumber(std::string phone_number);
    void        SetDarkestSecret(std::string darkest_secret);
    void        Display(void);

private:
    int         m_index;
    std::string m_first_name;
    std::string m_last_name;
    std::string m_nickname;
    std::string m_phone_number;
    std::string m_darkest_secret;
};

#endif // CONTACT_HPP