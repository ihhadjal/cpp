#include "phonebook.hpp"

int main()
{
	PhoneBook repo;
	Contact	  contacts;
	std::string str;

	while (1)
	{
		std::getline(std::cin, str);
		if (str == "EXIT")
			break ;
		else if (str == "ADD")
			repo.addFirstName(str);
	}
}

void	PhoneBook::addFirstName(std::string str)
{
	Contact test;
	std::cout << "insert first name: \n";
	std::getline(std::cin, str);
	test.setFirstName(str);
	std::cout << test.getFirstName() <<std::endl;
}

void	Contact::setFirstName(std::string firstname)
{
	this->m_firstName = firstname;
}

std::string	Contact::getFirstName()
{
	return m_firstName;
}