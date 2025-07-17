#include "Zombie.hpp"

void    Zombie::announce(){
    std::cout << this->m_name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie() : m_name("dafault")
{
}

Zombie::~Zombie(){
    std::cout << "zombie: " << this->m_name << " is dead\n";
}

void Zombie::setName(std::string name)
{
    this->m_name = name;
}