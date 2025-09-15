#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>

class Contact
{
    private:
    std::string m_firstName;
    std::string m_lastName; 
    std::string m_nickName;
    std::string m_darkestSecret;
    std::string m_phoneNumber;


    public:
    std::string getFirstName();
    void setFirstName(std::string firstName);
    std::string getLastName();
    void setLastName(std::string lastName);
    std::string getNickName();
    void setNickName(std::string nickName);
    std::string getDarkest();
    void setDarkest(std::string darkestSecret);
    std::string getPhone();
    void setPhone(std::string phoneNb);
};


class PhoneBook
{
    private:
    Contact m_contacts[8];
    int     m_index;

    public:
    PhoneBook();
    void addContact(std::string str);
    void searchContact(std::string str);
    int checkPhone(std::string str);
    int checkEmpty(std::string str);
	void printTable(int i);
	int checkLetters(std::string str);
};

#endif