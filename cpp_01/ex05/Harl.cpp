#include "Harl.hpp"

void    Harl::debug(){
    std::cout << "{DEBUG}" << std::endl;
    std::cout  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info(){
    std::cout << "{INFO}" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(){
    std::cout << "{WARNING}" << std::endl;
    std::cout << "think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void    Harl::error(){
    std::cout << "{ERROR}" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    typedef void(Harl::*arrayType)();

    arrayType array[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levelType[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (levelType[i] == level)
            (this->*array[i])();
    }
}