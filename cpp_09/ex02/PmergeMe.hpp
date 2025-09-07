#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <stdlib.h>

class Sort
{
    private:

    public:
    Sort();
    Sort(const Sort &src);
    ~Sort();
    Sort &operator=(const Sort &rhs);
    void    parse(char **argv);
};
#endif