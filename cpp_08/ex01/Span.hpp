#ifndef SPAN_HPP
#define SPAN_HPP


#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <exception>
#include <algorithm>
#include <bits/stdc++.h>

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
    int shortestSpan();
    int longestSpan();
    std::vector<unsigned int> _vct;

    class NoNumberStoredException : public std::exception
    {
        private:
        const char *_msg;

        public:
        NoNumberStoredException(const char *msg);
        const char *what() const throw();
    };
};

#endif