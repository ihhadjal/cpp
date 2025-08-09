#include "poly.hpp"

Dog::Dog() : Animal()
{
    _type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog &src) : Animal(src)
{
    std::cout << "Dog copy constructor called\n";
    _brain = new Brain(*src._brain);
    _type = src._type;
}

Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs)
    {
        _type = rhs._type;
        Brain *newBrain = new Brain(*rhs._brain);
        delete _brain;
        _brain = newBrain;
    }
    std::cout << "Dog copy assignment operator called\n";
    return (*this);
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << this->getType() << " makes wof\n";
}
