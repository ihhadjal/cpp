#include "ScalarConvert.hpp"

void ScalarConvert::convert(std::string toConvert)
{
    int Ivalue = atoi(toConvert.c_str());

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

