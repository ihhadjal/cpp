#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>

class Fixed 
{
    private:
    int _fixedValue;
    static const int _bits;

    public:
    Fixed(void);
    Fixed(Fixed const &source);
    ~Fixed(void);
    Fixed &operator=(Fixed const &rhs);
    int getRawBits(void)const;
    void setRawBits(int const raw);
};
#endif