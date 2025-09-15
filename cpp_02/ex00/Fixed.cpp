#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void) : _fixedValue(0){
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &source){ 
    std::cout << "Copy constructor called\n";
    *this = source;
}

Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called\n";
    return (this->_fixedValue);
}

void    Fixed::setRawBits(int const raw){
    this->_fixedValue = raw;
}

Fixed  &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Copy assignement operator called\n";
    this->_fixedValue = rhs.getRawBits();

    return *this;
}