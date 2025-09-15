#include "Zombie.hpp"

void    Zombie::announce()
{
    std::cout << this->m_name << ": BraiiiiiiinnnzzzZ..\n";
}


Zombie::Zombie(std::string name) : m_name(name)
{
}

Zombie::~Zombie()
{
    std::cout << "zombie: " << this->m_name << " is dead\n";
} 