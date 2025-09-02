#include "Span.hpp"

Span::Span() : _N(0){}

Span::Span(unsigned int n) : _N(n) {}

Span::Span(const Span &src){
    *this = src;
}

Span::~Span(){}

Span &Span::operator=(const Span &rhs)
{
    if (this != &rhs)
        this->_N = rhs._N;
    return *this;
}

void   Span::addNumber(unsigned int n)
{
}