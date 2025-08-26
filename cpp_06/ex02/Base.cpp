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
    {
        std::cout << "It's an A object\n";
        return new A;
    }
    else if (random == 1)
    {
        std::cout << "It's an B object\n";
        return new B;
    }
    else if (random == 2)
    {
        std::cout << "It's an C object\n";
        return new C;
    }
    return NULL;
}

void    identify(Base *p)
{
    std::cout << "pointer identifier called\n";
    if (dynamic_cast<A *>(p))
        std::cout << "p = A\n";
    else if (dynamic_cast<B *>(p))
        std::cout << "p = B\n";
    else if (dynamic_cast<C *>(p))
        std::cout << "p = C\n";
}

void    identify(Base &p)
{
    std::cout << "reference identifier called\n";
    Base &tmp = p;
    try
    {
        tmp = dynamic_cast<A&>(p);
        std::cout << "p = A\n";
    }
    catch(const std::bad_cast &)
    {
        try
        {
            tmp = dynamic_cast<B&>(p);
            std::cout << "p = B\n";
        }
        catch(const std::bad_cast &)
        {
            try
            {
                tmp = dynamic_cast<C&>(p);
                std::cout << "p = C\n";
            }
            catch(const std::bad_cast &){
            }
        }
    }
}