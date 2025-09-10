#include "PmergeMe.hpp"

Sort::Sort() : count(0){}

Sort::Sort(const Sort &src) { *this = src; }

Sort::~Sort() {}

Sort &Sort::operator=(const Sort &rhs)
{

    if (this != &rhs)
    {
        this->count =  rhs.count;
        this->_vct = rhs._vct;
        this->_lst = rhs._lst;
    }
    return *this;
}

void Sort::parseAndInit(char **argv)
{
    for (int i = 1; argv[i]; i++)
    {
        int num = atoi(argv[i]);
        this->_vct.push_back(num);
        this->_lst.push_back(num);
        for (int j = 0; argv[i][j]; j++)
        {
            if (argv[i][j] == '-')
            {
                std::cout << "Error: negative numbers are not allowed\n";
                exit(1);
            }
            if (!isdigit(argv[i][j]) && argv[i][j] != '+')
            {
                std::cout << "Error: int only are accepted\n";
                exit(1);
            }
        }
    }
}
void Sort::mergeSort(char **argv)
{
    this->parseAndInit(argv);
    std::cout << "Before: ";
    printContainer(this->_vct);
    sort(this->_vct);
    sort(this->_lst);
}

std::vector<int> Sort::generateJacobsthalSequence(int n)
{
    std::vector<int> jacobsthal;
    std::vector<int> jacobsthalNumbers;

    jacobsthalNumbers.push_back(0);
    jacobsthalNumbers.push_back(1);

    int current = 1;
    while (current < n)
    {
        int next = jacobsthalNumbers[jacobsthalNumbers.size() - 1] + 2 * jacobsthalNumbers[jacobsthalNumbers.size() - 2];
        jacobsthalNumbers.push_back(next);
        current = next;
    }

    int lastAdded = 1;

    for (size_t i = 2; i < jacobsthalNumbers.size() && jacobsthalNumbers[i] <= n; ++i)
    {
        int limit = jacobsthalNumbers[i];

        for (int j = std::min(limit, n); j > lastAdded; --j)
        {
            jacobsthal.push_back(j);
        }
        lastAdded = limit;
    }

    return jacobsthal;
}
