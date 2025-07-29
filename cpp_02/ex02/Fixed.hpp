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

    //--------EX01----------//
    Fixed();
    Fixed(Fixed const &source);
    Fixed(int const intValue);
    Fixed(float const floatValue);
    ~Fixed();
    float toFloat(void) const;
    int   toInt(void) const;
    int   getValue()const;
    Fixed &operator=(Fixed const &rhs);

    //--------EX02----------//
    bool operator<(Fixed const &rhs)const;
    bool operator>(Fixed const &rhs)const;
    bool operator<=(Fixed const &rhs)const;
    bool operator>=(Fixed const &rhs)const;
    bool operator==(Fixed const &rhs)const;
    bool operator!=(Fixed const &rhs)const;
    Fixed operator*(Fixed const &rhs);
    Fixed operator+(Fixed const &rhs);
    Fixed operator-(Fixed const &rhs);
    Fixed operator/(Fixed const &rhs);
    Fixed &operator++(); //pre-incrementation
    Fixed operator++(int); //post-incrementation
    Fixed &operator--(); //pre-decrementation
    Fixed operator--(int); //post-decrementation
    static Fixed min(const Fixed &n1, const Fixed &n2);
    static Fixed max(const Fixed &n1, const Fixed &n2);
    static Fixed min(Fixed &n1, Fixed &n2);
    static Fixed max(Fixed &n1, Fixed &n2);
};

std::ostream &operator<<(std::ostream  &o, const Fixed &i);

#endif