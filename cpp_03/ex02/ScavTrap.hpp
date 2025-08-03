#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <stdlib.h> 
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &src);
    ScavTrap &operator=(ScavTrap const &rhs);
    ~ScavTrap();

    std::string getName() const;
    void    guardGate();
    void    attack(std::string const &target);

};
#endif