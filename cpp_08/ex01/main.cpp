#include "Span.hpp"

int main()
{
    Span sp = Span(0);

    try
    {
        sp.addNumber(4);
        sp.addNumber(3);
    }
    catch(const std::exception& e)
    {
        std::cout << "error the array is full\n";
    }
}