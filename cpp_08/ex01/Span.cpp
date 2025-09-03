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
    {
        this->_N = rhs._N;
        this->_vct = rhs._vct;
    }
    return *this;
}

Span::NoNumberStoredException::NoNumberStoredException(const char *msg) : _msg(msg){}

const char *Span::NoNumberStoredException::what() const throw(){
    return _msg;
}

void   Span::addNumber(unsigned int n)
{
    Span::NoNumberStoredException exception("Error: the array is full\n");
    if (this->_vct.size() >= this->_N)
        throw exception;
    else
        this->_vct.push_back(n);
}

int  Span::longestSpan()
{
    Span::NoNumberStoredException exception("Error: no number stored / only one number is stored\n");
    if (this->_vct.size() == 0 || this->_vct.size() == 1) 
        throw exception;
    
    int min = *(std::min_element(this->_vct.begin(), this->_vct.end()));
    int max = *(std::max_element(this->_vct.begin(), this->_vct.end()));

    return (max - min);
}

int Span::shortestSpan()
{
    Span::NoNumberStoredException exception("Error: no number stored / only one number is stored\n");
    if (this->_vct.size() == 0 || this->_vct.size() == 1) 
        throw exception;
        
    std::sort(this->_vct.begin(), this->_vct.end());

    int x = this->_vct[0];
    int y = this->_vct[1];
    return (y - x);
}
