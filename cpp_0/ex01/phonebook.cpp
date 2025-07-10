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
			break;
		else if (str == "ADD")
			repo.addContact(str, contacts);
	}
}

void	PhoneBook::addContact(std::string str, Contact con)
{

}