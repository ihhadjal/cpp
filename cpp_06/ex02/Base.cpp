#include "Base.hpp"

Base::~Base()
{
    std::cout << "destructor called\n";
}

Base *generate(void)
{
    int random;

    srand(time(NULL));
    random = rand() % 3;

    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else if (random == 2)
        return new C;
    return NULL;
}

void    identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "p = A\n";
    else if (dynamic_cast<B *>(p))
        std::cout << "p = B\n";
    else if (dynamic_cast<C *>(p))
        std::cout << "p = C\n";
}

