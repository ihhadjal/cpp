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
        else if (str == "SEARCH")
            repo.searchContact(str);
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
	checkLetters(str);
    this->m_contacts[m_index].setFirstName(str);
    std::cout << "enter a last name: ";
    std::getline(std::cin, str);
    checkEmpty(str);
	checkLetters(str);
    this->m_contacts[m_index].setLastName(str);
    std::cout << "enter a nick name: ";
    std::getline(std::cin, str);
    checkEmpty(str);
	checkLetters(str);
    this->m_contacts[m_index].setNickName(str);
    std::cout << "enter a phone number: ";
    std::getline(std::cin, str);
    checkEmpty(str);
    checkPhone(str);
    this->m_contacts[m_index].setPhone(str);
    std::cout << "enter your deepest secret: ";
    std::getline(std::cin, str);
    checkEmpty(str);
	checkLetters(str);
    this->m_contacts[m_index].setDarkest(str);
    this->m_index = (this->m_index + 1) % 8;
}

void	PhoneBook::searchContact(std::string str)
{
	for (int i = 0; i != m_index; i++)
		printTable(i);
	std::cout << "wich contact would you like to see: ";
	std::getline(std::cin, str);
	int astr = atoi(str.c_str());
	std::cout << "first name: " << this->m_contacts[astr].getFirstName() << std::endl;
	std::cout << "last name: " << this->m_contacts[astr].getLastName() << std::endl;
	std::cout << "nick name: " << this->m_contacts[astr].getNickName() << std::endl;
	std::cout << "PhoneNumber: " << this->m_contacts[astr].getPhone() << std::endl;
	std::cout << "DarkestSecret: " << this->m_contacts[astr].getDarkest() << std::endl;

}

void	PhoneBook::printTable(int i)
{
	std::cout << i;
	std::cout << "   |   ";
	std::cout << this->m_contacts[i].getFirstName();
	std::cout << "   |   ";
	std::cout << this->m_contacts[i].getLastName();
	std::cout << "   |   ";
	std::cout << this->m_contacts[i].getNickName() << std::endl;
}