#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
    ClapTrap iheb("iheb");
    ClapTrap dren("dren");
    ScavTrap mew;
    mew.attack("iheb");
    mew.guardGate();
}
