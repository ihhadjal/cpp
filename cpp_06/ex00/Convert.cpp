#include "ScalarConvert.hpp"

void ScalarConvert::convert(std::string toConvert)
{
    int Ivalue = atoi(toConvert.c_str());
    char *endp;
    float conv = std::strtof(toConvert.c_str(), &endp);

    check_characters(toConvert);
    if (toConvert.length() > 1 && check_if_phrase(toConvert) == true)
    {
        std::cout << "error: cannot convert phrases\n";
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
        if (conv > FLT_MAX)
        {
            std::cout << "error: int overflow\n";
            exit (1);
        }
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
    check_special_cases(toConvert);
}
