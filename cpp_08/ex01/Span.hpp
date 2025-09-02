#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <exception>
#include <algorithm>

class Span
{
    private:
    unsigned int _N;

    public:
    Span();
    Span(unsigned int n);
    Span(const Span &src);
    ~Span();
    Span &operator=(const Span &rhs);

    void addNumber(unsigned int n);
    void shortestSpan(unsigned int n);
    void longestSpan(unsigned int n);
};


#endif