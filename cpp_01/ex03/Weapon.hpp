#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>

class Weapon{
    private:
    std::string m_type;

    public:
    std::string getType();
    void        setType(std::string type);
};
#endif