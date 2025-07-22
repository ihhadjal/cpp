#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "Weapon.hpp"

class HumanA
{
    private:
    std::string m_name;
    Weapon      &m_weapon;

    public:
    HumanA(std::string name, Weapon &weapon);
    void attack();
    std::string getType( void ) { return m_weapon.geType(); }
};
#endif