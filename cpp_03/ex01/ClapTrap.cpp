#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "Constructor has been called\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "Constructor has been called\n";
}

ClapTrap::ClapTrap(ClapTrap const &source){
    std::cout << "Copy constructor has been called\n";
    *this = source;
}

std::string    ClapTrap::getName()const{
    return (this->_name);
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs){
    this->_name = rhs.getName();

    return (*this);
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor has been called\n";
}

void    ClapTrap::attack(const std::string &target)
{
    this->_energyPoints--;
    if (this->_energyPoints == 0){
        std::cout << "ClapTrap " << this->getName() << " has no energy points\n";
        exit (1);
    }
    std::cout << "ClapTrap "<< this->getName() << " attacks " << target;
    std::cout << " causing " << this->_attackDamage << " points of damage\n";
        
}

void    ClapTrap::takeDamage(unsigned int amount){
    this->_hitPoints -= amount;
    std::cout << "ClapTrap " << this->getName() << " has taken " << amount << " points of damage\n";
}

void    ClapTrap::beRepaired(unsigned int amount){
    this->_energyPoints--;
    if (this->_energyPoints == 0){
        std::cout << "ClapTrap " << this->getName() << " has no energy points\n";
        exit (1);
    }
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << this->getName() << " repaired " << amount << " hit points\n";
}
    ScavTrap wof;
