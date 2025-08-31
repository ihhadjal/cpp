#include "iter.hpp"


int main(void)
{
    int a[5] = {0,1,2,3,4,};
    char b[5] = {'a', 'b', 'c', 'd', 'e',};
    float c[5] = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f};
    std::string d[5] = {"iheb", "bogoss", "geni", "trop fort", "lizhommes"};

    ::iter(a, 5, aff);
    std::cout << '\n';
    ::iter(b, 5, aff);
    std::cout << '\n';
    ::iter(c, 5, aff);
    std::cout << '\n';
    ::iter(d, 5, aff);
    std::cout << '\n';
}