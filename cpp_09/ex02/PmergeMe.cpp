#include "PmergeMe.hpp"

Sort::Sort(){}

Sort::Sort(const Sort &src){*this = src;}

Sort::~Sort(){}

Sort &Sort::operator=(const Sort &rhs){

    if (this != &rhs)
    {
        this->_vct = rhs._vct;
        this->_lst = rhs._lst;
    }
    return *this;
}

void    Sort::parseAndInit(char **argv)
{
    for (int i = 1; argv[i]; i++)
    {
        int num = atoi(argv[i]);
        this->_vct.push_back(num);
        this->_lst.push_back(num);
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
    std::cout << "Before: ";
    for (std::vector<unsigned int>::iterator it = this->_vct.begin(); it != this->_vct.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
}
void    Sort::mergeSort(char **argv)
{
    this->parseAndInit(argv);
}
