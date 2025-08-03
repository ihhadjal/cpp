#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <stdlib.h> 
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &src);
    FragTrap &operator=(const FragTrap &rhs);
    ~FragTrap();

    void    highFiveGuys(void);
    std::string getName()const;
};
#endif