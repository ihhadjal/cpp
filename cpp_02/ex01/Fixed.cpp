#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _value(0){
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &source){
    std::cout << "Copy constructor called\n";
    *this = source;
}

Fixed &Fixed::operator=(Fixed const &rhs){
    std::cout << "Copy assignement operator called\n";
    this->_value = rhs.getValue();

    return (*this);
}

Fixed::Fixed(int const intValue)
{
    this->_value = intValue << _bits;
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(float const floatValue)
{
    this->_value = static_cast<int>(roundf(floatValue * (1 << _bits)));
    std::cout << "Float constructor called\n";
}

int Fixed::getValue()const{
    return this->_value;
}

Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}

int Fixed::toInt(void) const{
    return (this->_value >> _bits);
}

float Fixed::toFloat(void) const{
    return (static_cast<float>(this->_value) / (1 << _bits));
}

std::ostream &operator<<(std::ostream &o, Fixed const &i){
    o << i.toFloat();
    return o;
}