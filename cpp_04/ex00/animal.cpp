#include "poly.hpp"


Animal::Animal(){
    std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal &src){
    std::cout << "Animal copy constructor called\n";
    *this = src;
}

Animal::Animal(std::string type) : _type(type){
    std::cout << "Animal default constructor called\n";
}

Animal &Animal::operator=(const Animal &rhs){
    this->_type = rhs._type;

    return *this;
}

Animal::~Animal(){
    std::cout << "Animal destructor called\n";
} 

std::string Animal::getType() const{
    return (this->_type);
}

void Animal::makeSound()const{
    std::cout << this->getType() << "makes a generic animal sound\n";
}