#include "Data.hpp"

Data::Data() : _id(0), _name("no name"), _value(0.0){
    std::cout << "Data default constructor called\n";
}

Data::Data(int id, const std::string name, double value) : _id(id), _name(name), _value(value){
    std::cout << "Data constructor called\n";
}

Data::Data(const Data &src)
{
    *this = src;

    std::cout << "Data copy constructor called\n";
}

Data &Data::operator=(const Data &rhs){
    if (this != &rhs)
    {
        this->_id = rhs._id;
        this->_name = rhs._name;
        this->_value = rhs._value;
    }

    return *this;
}

Data::~Data(){
    std::cout << "Data destructor called\n";
}

