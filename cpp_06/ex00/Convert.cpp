#include "ScalarConvert.hpp"

void ScalarConvert::convert(std::string toConvert)
{
    int Ivalue = atoi(toConvert.c_str());
    char *endp;
    float conv = std::strtof(toConvert.c_str(), &endp);

    if (conv > FLT_MAX || conv < FLT_MIN)
    {
        std::cout << "conversion impossible, int overflow\n";
        exit (1);
    }
    if ((toConvert[0] >= 33 && toConvert[0] <= 126) && toConvert.size() == 1 
        && check_if_num(toConvert) == false)
    {
        std::cout << "char: " << toConvert[0] << '\n';
        std::cout << "int: " << static_cast<int>(toConvert[0]) << '\n';
        std::cout << "float: " << static_cast<float>(toConvert[0])<< ".0f" << '\n';
        std::cout << "double: " << static_cast<double>(toConvert[0]) << ".0" << '\n';
    }
    if (check_if_num(toConvert) == true)
    {
        if (Ivalue >= 33 && Ivalue <= 126)
            std::cout << "char: " << static_cast<char>(Ivalue) << '\n';
        else
            std::cout << "char: not displayable\n";
        std::cout << "int: " << conv << '\n';
        std::cout << "float: " << static_cast<float>(conv) << ".0f" << '\n';
        std::cout << "double: " << static_cast<double>(conv) << ".0" <<'\n';
    }
    if (check_if_float(toConvert) == true)
    {
        if (conv >= 33 && conv <= 126)
            std::cout << "char: " << static_cast<char>(conv) << '\n';
        else
            std::cout << "char: not displayable\n";
        std::cout << "int: " << static_cast<int>(conv) << '\n';
        std::cout << "float: " << toConvert << '\n';
        if (check_special_double(toConvert) == false)
            std::cout << "double: " << conv << '\n';
        else
            std::cout << "double: " << conv << ".0" << '\n';

    }
    if (check_if_double(toConvert) == true)
    {
        if (conv >= 33 && conv <= 126)
            std::cout << "char: " << static_cast<char>(conv) << '\n';
        else
            std::cout << "char: not displayable\n";
        std::cout << "int: " << static_cast<int>(conv) << '\n';
        std::cout << "float: " << toConvert << "f" << '\n';
        std::cout << "double: " << toConvert << '\n';
    }
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


bool    check_if_num(std::string str)
{
    size_t c = 0;
    for (int i = 0; str[i]; i++)
    {
        if (isdigit(str[i]) || str[i] == '-' || str[i] == '+')
            c++;
    }
    if (c == strlen(str.c_str()))
        return true;
    return false;
}
