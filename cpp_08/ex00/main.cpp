#include "easyfind.hpp"

int main()
{
    std::list<int>  lst;

    for (int i = 0; i < 10; i++)
        lst.push_back(i + 1);
    try
    {
        easyfind(lst, 56);
    }
    catch(const std::exception &e)
    {
        std::cout << "the number is not in the list\n";
    }
} 