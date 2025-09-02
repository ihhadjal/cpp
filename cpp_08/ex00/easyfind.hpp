#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <exception>
#include <algorithm>

template<typename T>

void easyfind(T &toSearch, int toFind)
{
    std::list<int>::iterator it;

    it = std::find(toSearch.begin(), toSearch.end(), toFind);
    if (it != toSearch.end())
        std::cout << "integer found: " << toFind << '\n';
    else
        throw std::exception();
}
#endif