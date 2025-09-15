#ifndef REPLACE_HPP 
#define REPLACE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <ostream>

class Swap
{
    private:
    std::string m_toFind;
    std::string m_replacer;

    public:
    Swap(std::string s1, std::string s2);
    std::string getFind();
    std::string getReplace();
    void        setFind(std::string tofind);
    void        setReplace(std::string replacer);
    void        replace(char *filename);
};

void    parsing(int argc, char **argv);
#endif