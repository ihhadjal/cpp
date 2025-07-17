#include "Zombie.hpp"


int main()
{
    Zombie *newZ = newZombie("zombie 1");

    newZ->announce();
    randomChump("zombie 2");
    
    delete newZ;
    return 0;
}