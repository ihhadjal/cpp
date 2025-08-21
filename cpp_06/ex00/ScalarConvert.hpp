#ifndef SCALAR_CONVERT_HPP
#define SCALAR_CONVERT_HPP


#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>

class ScalarConvert
{
    private:
    ScalarConvert();
    ScalarConvert(const ScalarConvert &src);
    ~ScalarConvert();
    ScalarConvert &operator=(const ScalarConvert &rhs);

    public:
    static void convert(std::string toConvert);
};

bool    check_if_num(std::string str);
#endif