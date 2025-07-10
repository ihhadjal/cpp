#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

class Contact
{
	public:

	private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_nickName;
	std::string m_darkestSecret;
	int	m_phoneNumber;
};

class PhoneBook
{
	public:
	void addContact(std::string str);
	private:
	Contact m_contacts[8];
};


#endif