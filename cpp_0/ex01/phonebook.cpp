#include "phonebook.hpp"

int main(void)
{
    PhoneBook repo;
    std::string str;

    while (1)
    {
        std::cout << "enter a command: ";
        std::getline(std::cin, str);
        if (str == "EXIT")
            break;
        else if (str == "ADD")
            repo.addContact(str);
        else if (str == "SEARCH")
            repo.searchContact(str);
    }
}

PhoneBook::PhoneBook(): m_index(0)
{
}

void    PhoneBook::addContact(std::string str)
{
    int index = this->m_index % 8;
    std::cout << "enter a first name: ";
    std::getline(std::cin, str);
    while (checkEmpty(str) == 0)
        std::getline(std::cin, str);
    while (checkLetters(str) == 0)
    {
        std::getline(std::cin, str);
        while (checkEmpty(str) == 0)
            std::getline(std::cin, str);
        this->m_contacts[index].setFirstName(str);
    }
    if (checkLetters(str) == 1)
        this->m_contacts[index].setFirstName(str);
    std::cout << "enter a last name: ";
    std::getline(std::cin, str);
    while (checkEmpty(str) == 0)
        std::getline(std::cin, str);
    while (checkLetters(str) == 0)
    {
        std::getline(std::cin, str);
        while (checkEmpty(str) == 0)
            std::getline(std::cin, str);
        this->m_contacts[index].setLastName(str);
    }
    if (checkLetters(str) == 1)
        this->m_contacts[index].setLastName(str);
    std::cout << "enter a nick name: ";
    std::getline(std::cin, str);
    while (checkEmpty(str) == 0)
        std::getline(std::cin, str);
    while (checkLetters(str) == 0)
    {
        std::getline(std::cin, str);
        while (checkEmpty(str) == 0)
            std::getline(std::cin, str);
        this->m_contacts[index].setNickName(str);
    }
    if (checkLetters(str) == 1)
        this->m_contacts[index].setNickName(str);
    std::cout << "enter a phone number: ";
    std::getline(std::cin, str);
    while (checkEmpty(str) == 0)
        std::getline(std::cin, str);
    while (checkPhone(str) == 0)
    {
        std::getline(std::cin, str);
        while (checkEmpty(str) == 0)
            std::getline(std::cin, str);
        this->m_contacts[index].setPhone(str);
    }
    if (checkPhone(str) == 1)
        this->m_contacts[index].setPhone(str);
    std::cout << "enter your darkest secret: ";
    std::getline(std::cin, str);
    while (checkEmpty(str) == 0)
        std::getline(std::cin, str);
    while (checkLetters(str) == 0)
    {
        std::getline(std::cin, str);
        while (checkEmpty(str) == 0)
            std::getline(std::cin, str);
        this->m_contacts[index].setDarkest(str);
    }
    if (checkLetters(str) == 1)
        this->m_contacts[index].setDarkest(str);
    this->m_index = this->m_index + 1;
}

void	PhoneBook::searchContact(std::string str)
{
    int max_coontacts;
    if (m_index > 8)
        max_coontacts = 8;
    else
        max_coontacts = m_index;
    for (int i = 0; i < max_coontacts; i++)
		printTable(i);
    if (!this->m_contacts->getFirstName().empty() && !this->m_contacts->getLastName().empty() 
        && !this->m_contacts->getNickName().empty() && !this->m_contacts->getPhone().empty() 
        && !this->m_contacts->getDarkest().empty())
    {
            std::cout << "wich contact would you like to see: ";
            std::getline(std::cin, str);
            int astr = atoi(str.c_str());
            if (astr < max_coontacts && astr >= 0)
            {
                std::cout << "first name: " << this->m_contacts[astr].getFirstName() << std::endl;
                std::cout << "last name: " << this->m_contacts[astr].getLastName() << std::endl;
                std::cout << "nick name: " << this->m_contacts[astr].getNickName() << std::endl;
                std::cout << "phone number: " << this->m_contacts[astr].getPhone() << std::endl;
                std::cout << "darkest secret: " << this->m_contacts[astr].getDarkest() << std::endl;
            }
            else
                std::cout << "the contact does not exist\n";
    }
    else
        std::cout << "the repo is empty please add a contact or insert a contact information\n";

}


void    PhoneBook::printTable(int i)
{
    std::string firstname = this->m_contacts[i].getFirstName();
    std::string lastname = this->m_contacts[i].getLastName();
    std::string nickname = this->m_contacts[i].getNickName();

    if (firstname.length() > 10)
        firstname = firstname.substr(0, 9) + ".";
    if (lastname.length() > 10)
        lastname = lastname.substr(0, 9) + ".";
    if (nickname.length() > 10)
        nickname = nickname.substr(0, 9) + ".";
    
    std::cout << std::setw(10) << i << '|';
    std::cout << std::setw(10) << firstname << '|';
    std::cout << std::setw(10) << lastname << '|';
    std::cout << std::setw(10) << nickname << std::endl;
}
