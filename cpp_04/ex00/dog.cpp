#include "poly.hpp"

Dog::Dog() : Animal(){
    _type = "Dog";
    std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog &src) : Animal(src){
    *this = src;
    std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator=(const Dog &rhs)
{
    this->_type = rhs.getType();

    return (*this);
}

Dog::~Dog(){
    std::cout << "Dog destructor called\n";
}

void    Dog::makeSound()const{
    std::cout << this->getType() << " makes wof\n";
}
