#include "ScalarConvert.hpp"


void    check_special_cases(std::string toConvert)
{
    if (toConvert == "nan" || toConvert == "nanf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
    }
    if (toConvert == "-inff" || toConvert == "+inff" 
        || toConvert == "-inf" || toConvert == "+inf")
    {
        if (toConvert == "-inff" || toConvert == "-inf")
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: -inff\n";
            std::cout << "double: -inf\n";
        }
        else
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: +inff\n";
            std::cout << "double: +inf\n";
        }
    }
}

bool    check_if_double(std::string str)
{
    int p = 0;
    int f = 0;
    for(int i = 0; str[i]; i++)
    {
        if (str[i] == '.')
            p++;
        if (str[i] == 'f')
            f++;
    }
    if (p == 1 && f == 0)
        return true;
    return false;
}

bool    check_special_double(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if ((str[i] == '.' && str[i + 1] == '0') || (str[i] == '.' && str[i + 1] == '\0')
            || (str[i] == '.' && str[i + 1] == 'f'))
            return true;
    }
    return false;
}

bool    check_if_float(std::string str)
{
    int c = 0;
    int f = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '.')
            c++;
        if (str[i] == 'f')
            f++;
    }
    if (c == 1 && f == 1)
        return true;
    return false;
}


void    check_characters(std::string str)
{
    bool flag = 0;

    for(int i = 0; str[i]; i++)
    {
        if (isdigit(str[i]))
            flag = 1;
        if ((flag == 1 && (str[i] >= 33 && str[i] <= 45)) 
            || (flag == 1 && ((str[i] >= 58 && str[i] <= 101) 
            || (flag == 1 && (str[i] >= 103 && str[i] <= 126))
            || (flag == 1 && str[i] == 47))))
        {
            std::cout << "error: int does not support characters\n";
            exit (1);
        }
    }
}

bool    check_if_num(std::string str)
{
    size_t c = 0;
    for (int i = 0; str[i]; i++)
    {
        if (isdigit(str[i]) || (strlen(str.c_str()) > 1 && str[i] == '+') || (strlen(str.c_str()) > 1 && str[i] == '-'))
            c++;
        if (str[i] == ' ' || str[i] == '\t' || (str[i] >= 0 && str[i] <= 32) 
            || str[i] == 127)
        {
            std::cout << "error: blank/white spaces are not allowed\n";
            exit (1);
        }
    }
    if (c == strlen(str.c_str()))
        return true;
    return false;
}

bool check_if_phrase(std::string str)
{
    size_t c = 0;

    for (int i = 0; str[i]; i++)
    {
        if (isalpha(str[i]))
            c++;
    }
    if (c == strlen(str.c_str()) && str != "nan" && str != "nanf" && str != "+inff" 
        && str != "-inff" && str != "+inf" && str != "-inf")
        return true;
    return false;
}