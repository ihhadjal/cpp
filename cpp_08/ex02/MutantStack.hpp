#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


#include <stack>
#include <iterator>
#include <iostream>

template<typename T>

class MutantStack : public std::stack<T>
{
    public:
    MutantStack():std::stack<T>(){}
    ~MutantStack(){}
    MutantStack(const MutantStack &src) : std::stack<T>(src){}
    MutantStack &operator=(const MutantStack &rhs){
        std::stack<T>::operator=(rhs);
        return *this;
    }
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() {return this->c.begin();}
    iterator end() {return this->c.end();}
};

#endif