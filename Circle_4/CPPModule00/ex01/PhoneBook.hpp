#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define RESET		"\033[0m"
# define GRAY		"\033[1;90m"
# define RED		"\033[1;91m"
# define GREEN		"\033[1;92m"
# define YELLOW		"\033[1;93m"
# define BLUE		"\033[1;94m"
# define MAGENTA	"\033[1;95m"
# define CYAN		"\033[1;96m"

# define PHONEBOOK_SIZE 8

class PhoneBook {
public:
    PhoneBook(void);
    void Run(void);

private:
    void add(void);
    void search(void);
    bool isEmptyString(std::string str);
    std::string getAddInput(std::string message);
    void printColumn(std::string str);
    bool isRightSearchInput(std::string input);
    void displaySavedContacts(void);
    void displayContact(int idx);

    Contact m_contacts[PHONEBOOK_SIZE];
    int     m_num_of_contacts;
    int     m_last_contact_idx;
};

#endif // PHOBEBOOK_HPP