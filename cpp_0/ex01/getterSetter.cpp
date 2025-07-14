#include "phonebook.hpp"



std::string Contact::getFirstName(){
    return(this->m_firstName);
}

void Contact::setFirstName(std::string firstName){
    this->m_firstName = firstName;
}

std::string Contact::getLastName(){
    return(this->m_lastName);
}

void Contact::setLastName(std::string lastName){
    this->m_lastName = lastName;
}

std::string Contact::getNickName(){
    return(this->m_nickName);
}

void Contact::setNickName(std::string nickName){
    this->m_nickName = nickName;
}

std::string Contact::getDarkest(){
    return(this->m_darkestSecret);
}

void Contact::setDarkest(std::string darkestSecret){
    this->m_darkestSecret = darkestSecret;
}

std::string Contact::getPhone(){
    return(this->m_phoneNumber);
}

void Contact::setPhone(std::string phoneNb){
    this->m_phoneNumber = phoneNb;
}

int    PhoneBook::checkEmpty(std::string str)
{ 
    while (str.empty() || str[0] == ' ')
    {
        std::cout << "line can not be empty try again: ";
        return (0);
    }
    return (1);
}

int PhoneBook::checkPhone(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        while (!isdigit(str[i]))
        {
            std::cout << "only numbers are accepted try again: ";
            return (0);
        }
    }
    return (1);
}

int PhoneBook::checkLetters(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        while (isdigit(str[i]))
        {
            std::cout << "only letters are accepted try again: ";
            return (0);
        }
    }
    return (1);
}