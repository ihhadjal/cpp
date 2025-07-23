#include "replace.hpp"

Swap::Swap(std::string s1, std::string s2) : m_toFind(s1), m_replacer(s2)
{
}

std::string Swap::getFind()
{
	return (this->m_toFind);
}

std::string Swap::getReplace()
{
	return (this->m_replacer);
}

void Swap::setFind(std::string tofind)
{
	this->m_toFind = tofind;
}

void Swap::setReplace(std::string replacer)
{
	this->m_replacer = replacer;
}

void Swap::replace(char *filename)
{
	std::string s1 = this->getFind();
	std::string s2 = this->getReplace();
	std::string newStr;
	std::fstream fd;
	size_t pos;

	fd.open(filename, std::fstream::in | std::fstream::out);
	if (!fd)
	{
		std::cout << "error: can not open file\n";
		exit(1);
	}
	while (getline(fd, newStr))
	{
        pos = newStr.find(s1);
        while (pos != std::string::npos){
            size_t i = 0;
            size_t j = pos;
            while (i < s2.size() && s2[i] && newStr[j]){
                newStr[j++] = s2[i++];
            }
            pos = newStr.find(s1, pos + s1.size());
        }
	}
    std::cout << newStr << std::endl;
    fd.close();
}
