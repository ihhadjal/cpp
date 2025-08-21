#include "ScalarConvert.hpp"

void ScalarConvert::convert(std::string toConvert)
{
    int Ivalue = atoi(toConvert.c_str());
    char *endp;
    float conv = std::strtof(toConvert.c_str(), &endp);

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
        std::cout << "int: " << Ivalue << '\n';
        std::cout << "float: " << static_cast<float>(Ivalue) << ".0f" << '\n';
        std::cout << "double: " << static_cast<double>(Ivalue) << '\n';
    }
    if (check_if_float(toConvert) == true)
    {
        if (conv >= 33 && conv <= 126)
            std::cout << "char: " << static_cast<char>(conv) << '\n';
        else
            std::cout << "char: not displayable\n";
        std::cout << "int: " << static_cast<int>(conv) << '\n';
        std::cout << "float: " << toConvert << '\n';
        std::cout << "double: " << conv << '\n';
    }
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

