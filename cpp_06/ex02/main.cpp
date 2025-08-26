#include "Base.hpp"

int main()
{
    Base *base  = generate();

    identify(base);
    delete base;
}