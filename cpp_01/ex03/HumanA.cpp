#include "HumanA.hpp"

void    HumanA::attack(){
    std::cout << this->m_name << " attacks with their weapon " << this->m_weapon.geType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : m_name(name), m_weapon(weapon)
{
}