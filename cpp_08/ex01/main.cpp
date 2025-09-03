#include "Span.hpp"

int main()
{
    Span sp = Span(1000000);

    try
    {
        sp.fillArray(1000000);
        std::cout << sp.shortestSpan() << '\n';
        std::cout << sp.longestSpan() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cout << e.what();
        exit (1);
    }
}