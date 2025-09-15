#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType) : m_type(weaponType)
{
}

std::string const &Weapon::geType(){
    return (this->m_type);
}

void    Weapon::setType(std::string type){
    this->m_type = type;
} 
