#include "phonebook.hpp"

int main(void)
{
    PhoneBook repo;
    Contact   contacts;
    std::string str;

    while (1)
    {
        std::cout << "enter a command: ";
        std::getline(std::cin, str);
        if (str == "EXIT")
            break;
        else if (str == "ADD")
            repo.addContact(str);
        // else if (str == "SEARCH")
        //     repo.searchContact(str);
    }
}
PhoneBook::PhoneBook(): m_index(0)
{
}
void    PhoneBook::addContact(std::string str)
{
    std::cout << "enter a first name: ";
    std::getline(std::cin, str);
    checkEmpty(str);
    this->m_contacts[m_index].setFirstName(str);
    std::cout << "enter a last name: ";
    std::getline(std::cin, str);
    checkEmpty(str);
    this->m_contacts[m_index].setLastName(str);
    std::cout << "enter a nick name: ";
    std::getline(std::cin, str);
    checkEmpty(str);
    this->m_contacts[m_index].setNickName(str);
    std::cout << "enter a phone number: ";
    std::getline(std::cin, str);
    checkEmpty(str);
    checkPhone(str);
    this->m_contacts[m_index].setPhone(str);
    std::cout << "enter your deepest secret: ";
    std::getline(std::cin, str);
    checkEmpty(str);
    this->m_contacts[m_index].setDarkest(str);
    this->m_index = (this->m_index + 1) % 8;
}

void PhoneBook::checkPhone(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        while (!isdigit(str[i]))
        {
            std::cout << "only numbers are accepted try again: ";
            std::getline(std::cin, str);
        }
    }
}