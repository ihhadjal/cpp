#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap(){
        _hitPoints = 100;
        _energyPoints = 50;
        _attackDamage = 20;
    std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(std::string name)
    :ClapTrap(name){
        _hitPoints = 100;
        _energyPoints = 50;
        _attackDamage = 20;
    std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(ScavTrap const &src){
    std::cout << "ScavTrap copy constructor called\n";
    *this = src;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
    this->_name = rhs.getName();

    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called\n";
}

std::string ScavTrap::getName() const{
    return (this->_name);
}

void   ScavTrap::guardGate(){
    std::cout << "Scav trap " << this->getName() << " is now in gate keeper mode\n";
}

void    ScavTrap::attack(const std::string &target)
{
    this->_energyPoints--;
    if (this->_energyPoints == 0){
        std::cout << "ScavTrap " << this->getName() << " has no energy points\n";
        exit (1);
    }
    std::cout << "ScavTrap "<< this->getName() << " attacks " << target;
    std::cout << " causing " << this->_attackDamage << " points of damage\n";
        
}