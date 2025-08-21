#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert(){
    std::cout << "Default constructor has been called\n";
}

ScalarConvert::ScalarConvert(const ScalarConvert &src){
    *this = src;

    std::cout << "Copy constructor called\n";
}

ScalarConvert::~ScalarConvert(){
    std::cout << "Destructor called\n";
}

ScalarConvert &ScalarConvert::operator=(const ScalarConvert &rhs)
{
    if (this != &rhs)
        //ScalarConvert has no variables to copy
    std::cout << "copy operator called\n";

    return *this;
}


