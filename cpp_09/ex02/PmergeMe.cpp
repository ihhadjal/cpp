#include "PmergeMe.hpp"

Sort::Sort(){}

Sort::Sort(const Sort &src){*this = src;}

Sort::~Sort(){}

Sort &Sort::operator=(const Sort &rhs){

    if (this != &rhs)
    {
        //nothing to copy
    }
    return *this;
}

void    Sort::parse(char **argv)
{
    for (int i = 1; argv[i]; ++i)
    {
        for (int j= 0; argv[i][j]; j++)
        {
            if (argv[i][j] == '-')
            {
                std::cout << "Error: negative numbers are not allowed\n";
                exit (1);
            }
            if (!isdigit(argv[i][j]) && argv[i][j] != '+')
            {
                std::cout << "Error: int only are accepted\n";
                exit (1);
            }
        }
    }
    
}