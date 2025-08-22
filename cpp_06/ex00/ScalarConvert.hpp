#ifndef SCALAR_CONVERT_HPP
#define SCALAR_CONVERT_HPP


#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <limits.h>

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
bool    check_if_float(std::string str);
bool    check_special_double(std::string str);
bool    check_if_double(std::string str);
void    check_special_cases(std::string toConvert);
void    check_characters(std::string str);
#endif