#include "poly.hpp"

Cat::Cat() : Animal()
{
    _type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat &src) : Animal(src)
{
    std::cout << "Cat copy constructor called\n";
    _brain = new Brain(*src._brain);
    _type = src._type;
}
Cat &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs)
    {
        _type = rhs._type;
        Brain *newBrain = new Brain(*rhs._brain);
        delete _brain;
        _brain = newBrain;
    }
    std::cout << "Cat copy assignment operator called\n";
    return *this;
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
    std::cout << this->getType() << " makes mew\n";
}