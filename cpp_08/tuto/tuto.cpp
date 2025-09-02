#include <iostream>
#include <map>
#include <vector>
#include <list>

class IOperation;

int main()
{
    std::list<int>                      lst1;
    std::map<std::string, IOperation *> map1;
    std::vector<int>                    v1;
    std::vector<int>                    v2;

    std::list<int>::const_iterator it;
    std::list<int>::const_iterator ite = lst1.end();

    for (it = lst1.begin(); it != ite; ++it)
        std::cout << *it << '\n';
}