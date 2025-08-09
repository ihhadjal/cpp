#include "poly.hpp"


WrongAnimal::WrongAnimal(){
    this->_type = "wrong animal";
    std::cout << "wrong animal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src){
    *this = src;
    std::cout << "wrong animal copy constructor called";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
    this->_type = rhs._type;

    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "wrong animal destructor called\n";
}

void WrongAnimal::makeSound()const{
    std::cout << "Wrong animal noise\n";
}

WrongCat::WrongCat() : WrongAnimal(){
    this->_type = "wrong cat";
    std::cout << "wrong Cat constructor called\n";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(){
    *this = src;
    std::cout << "wrong Cat copy constructor called";
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
    this->_type = rhs._type;

    return *this;
}

WrongCat::~WrongCat(){
    std::cout << "wrong Cat destructor called\n";
}

void WrongCat::makeSound()const{
    std::cout << "Wrong Cat noise\n";
}

std::string WrongAnimal::getType() const{
    return this->_type;
}