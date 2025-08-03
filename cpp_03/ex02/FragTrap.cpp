#include "FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap(){
        _hitPoints = 100;
        _energyPoints = 100;
        _attackDamage = 30;
    std::cout << "FragTrap constructor called\n";
}

FragTrap::FragTrap(std::string name)
    :ClapTrap(name){
        _hitPoints = 100;
        _energyPoints = 100;
        _attackDamage = 30;
    std::cout << "FragTrap constructor called\n";
}

FragTrap::FragTrap(FragTrap const &src){
    std::cout << "FragTrap copy constructor called\n";
    *this = src;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
    this->_name = rhs.getName();

    return *this;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called\n";
}

std::string FragTrap::getName() const{
    return (this->_name);
}

void    FragTrap::highFiveGuys(){
    std::cout << "Give me a high five guys\n";
}