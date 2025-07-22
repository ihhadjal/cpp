#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "Weapon.hpp"

class HumanB
{
    private:
    std::string m_name;
    Weapon      *m_weapon;

    public:
    HumanB(std::string name);
    void setWeapon(Weapon &weapon);
    void attack();
};
#endif