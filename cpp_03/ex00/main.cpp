#include "ClapTrap.hpp"

int main()
{
    ClapTrap iheb("iheb");
    ClapTrap dren("dren");

    iheb.attack(dren.getName());
    dren.beRepaired(10);
}