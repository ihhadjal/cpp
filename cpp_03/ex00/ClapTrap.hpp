#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <stdlib.h> 
class ClapTrap
{
    private:
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;

    public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const &source);
    ClapTrap &operator=(ClapTrap const &rhs);
    ~ClapTrap();

    void    attack(const std::string &target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

    std::string getName()const;
};
#endif