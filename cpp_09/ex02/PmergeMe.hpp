#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <stdlib.h>
#include <vector>
#include <deque>

class Sort
{
    private:
    std::vector<unsigned int> _vct;
    std::deque<unsigned int> _lst;

    public:
    Sort();
    Sort(const Sort &src);
    ~Sort();
    Sort &operator=(const Sort &rhs);
    void    parseAndInit(char **argv);
    void    mergeSort(char **argv);
};
#endif