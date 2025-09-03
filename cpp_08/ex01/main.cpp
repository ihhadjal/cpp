#include "Span.hpp"

int main()
{
    Span sp = Span(10);

    try
    {
        sp.addNumber(50);
        sp.addNumber(100);
        sp.addNumber(130);
        sp.addNumber(1000);
        std::cout << sp.shortestSpan() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cout << e.what();
        exit (1);
    }
}