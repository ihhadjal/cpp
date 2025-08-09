#include "brain.hpp"
#include "poly.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called\n";
    for (int i = 0; i < 100; ++i)
        _ideas[i] = "(empty idea)";
}

Brain::Brain(const Brain &src)
{
    std::cout << "Brain copy constructor called\n";
    *this = src;
}

Brain &Brain::operator=(const Brain &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = rhs._ideas[i];
    }
    std::cout << "Brain copy assignment operator called\n";
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";
}
