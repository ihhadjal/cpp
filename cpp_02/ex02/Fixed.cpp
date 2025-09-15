#include "Fixed.hpp"


//--------------------------------------EX01-----------------------------------//

const int Fixed::_bits = 8;

Fixed::Fixed() : _value(0){
}

Fixed::Fixed(Fixed const &source){
    *this = source;
}

Fixed &Fixed::operator=(Fixed const &rhs){
    this->_value = rhs.getValue(); 

    return (*this);
}

Fixed::Fixed(int const intValue)
{
    this->_value = intValue << _bits;
}

Fixed::Fixed(float const floatValue)
{
    this->_value = static_cast<int>(roundf(floatValue * (1 << _bits)));
}

int Fixed::getValue()const{
    return this->_value;
}

Fixed::~Fixed(){
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



//--------------------------------------EX02-----------------------------------//

bool    Fixed::operator>(Fixed const &rhs)const{
    if (this->_value > rhs.getValue())
        return true;
    else
        return false;
}

bool    Fixed::operator<(Fixed const &rhs)const{
    if (this->_value < rhs.getValue())
        return true;
    else
        return false;
}


bool    Fixed::operator>=(Fixed const &rhs)const{
    if (this->_value >= rhs.getValue())
        return true;
    else
        return false;
}

bool    Fixed::operator<=(Fixed const &rhs)const{
    if (this->_value <= rhs.getValue())
        return true;
    else
        return false;
}

bool    Fixed::operator==(Fixed const &rhs)const{
    if (this->_value == rhs.getValue())
        return true;
    else
        return false;
}

bool    Fixed::operator!=(Fixed const &rhs)const{
    if (this->_value != rhs.getValue())
        return true;
    else
        return false;
}

Fixed   Fixed::operator*(Fixed const &rhs){
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed   Fixed::operator+(Fixed const &rhs){
    return Fixed(this->toFloat() + rhs.toFloat());
}
Fixed   Fixed::operator-(Fixed const &rhs){
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed   Fixed::operator/(Fixed const &rhs){
    if (rhs.toFloat() == 0){
        std::cout << "cannot divide by 0\n";
        exit (1);
    }
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++(){
    ++_value;
    return (*this);
}

Fixed Fixed::operator++(int){
    Fixed temp = *this;
    ++_value;
    return (temp);
}

Fixed &Fixed::operator--(){
    --_value;
    return (*this);
}

Fixed Fixed::operator--(int){
    Fixed temp = *this;
    --_value;
    return (temp);
}

Fixed Fixed::min(Fixed &n1, Fixed &n2)
{
    if (n1 < n2)
        return (n1);
    return (n2);
}

Fixed Fixed::max(Fixed &n1, Fixed &n2)
{
    if (n1 > n2)
        return (n1);
    return (n2);
}

Fixed Fixed::min(const Fixed &n1, const Fixed &n2)
{
    if (n1 < n2)
        return (n1);
    return (n2);
}

Fixed Fixed::max(const Fixed &n1, const Fixed &n2)
{
    if (n1 > n2)
        return (n1);
    return (n2);
}