#include "HumanB.hpp"


void    HumanB::attack(){
    std::cout << this->m_name << " attacks with their weapon " << this->m_weapon->geType() << std::endl;
}

HumanB::HumanB(std::string name) : m_name(name)
{
}

void HumanB::setWeapon(Weapon &weapon){
    this->m_weapon = &weapon;
}
 