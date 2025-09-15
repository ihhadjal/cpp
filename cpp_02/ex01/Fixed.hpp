#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private: 
    const static int _bits;
    int      _value;

    public:
    Fixed();
    Fixed(Fixed const &source);
    Fixed(int const intValue);
    Fixed(float const floatValue);
    ~Fixed();
    Fixed &operator=(Fixed const &rhs);
    float toFloat(void) const;
    int   toInt(void) const;
    int   getValue() const;
};

std::ostream &operator<<(std::ostream  &o, const Fixed &i);
#endif