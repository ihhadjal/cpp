#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data 
{
    public:
    int _id;
    std::string _name;
    double  _value;

    Data();
    Data(int id, const std::string name, double value);
    Data(const Data &src);
    Data &operator=(const Data &rhs);
    ~Data();
};

#endif

