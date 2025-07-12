#include "phonebook.hpp"

int main(void)
{
    PhoneBook repo;
    Contact   contacts;
    std::string str;

    while (1)
    {
        std::getline(std::cin, str);
        if (str == "EXIT")
            break;
        else if (str == "ADD")
            repo.addContact(str);
    }
}
PhoneBook::PhoneBook(): m_index(0)
{
}

void    PhoneBook::addContact(std::string str)
{
    std::cout << "enter a first name\n";
    std::getline(std::cin, str);
    this->m_contacts[m_index].setFirstName(str);
    std::cout << "enter a last name\n";
    std::getline(std::cin, str);
    this->m_contacts[m_index].setLastName(str);
    std::cout << "enter a nick name\n";
    std::getline(std::cin, str);
    this->m_contacts[m_index].setNickName(str);
    std::cout << "enter a phone number\n";
    std::getline(std::cin, str);
    this->m_contacts[m_index].setPhone(str);
    std::cout << "enter your deepest secret\n";
    std::getline(std::cin, str);
    this->m_contacts[m_index].setDarkest(str);
    this->m_index = (this->m_index + 1) % 8;
}
