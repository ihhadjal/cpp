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
    std::string line;
	std::fstream fd;
    std::ofstream newFile;
	size_t pos;
    bool    found = false;
    
	fd.open(filename, std::fstream::in | std::fstream::out);
	if (!fd)
	{
        std::cout << "error: can not open file\n";
		exit(1);
	}
	while (getline(fd, line))
	{
        pos = line.find(s1);
        while (pos != std::string::npos)
        {
            line.erase(pos, s1.size());
            line.insert(pos, s2);
            pos = line.find(s1, pos + s2.size());
            found = true;
        }
        newStr += line;
        newStr += '\n';
    }
    if (found == false){
        std::cout << "word not found\n";
        exit (1);
    }
    else
    {
        std::string newFileName = std::string(filename) + ".replace";
        newFile.open(newFileName.c_str());
        newFile << newStr;
        newFile.close();
    }
    fd.close();
}