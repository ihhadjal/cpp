#include "poly.hpp"

Cat::Cat() : Animal(){
    _type = "Cat";
    std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat &src) : Animal(src)
{
    *this = src;
    std::cout << "Cat copy constructor called\n";
}
Cat &Cat::operator=(const Cat &rhs)
{
    this->_type = rhs.getType();

    return *this;
}

Cat::~Cat(){
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound()const
{
    std::cout << this->getType() << " makes mew\n";
}