#include "Zombie.hpp"


int main()
{
    Zombie *newZ = newZombie("zombie 1");
    Zombie *newZ1 = newZombie("zombie 2");
    Zombie *newZ2 = newZombie("zombie 3");
    Zombie *newZ3 = newZombie("zombie 4");

    newZ->announce();
    newZ1->announce();
    newZ2->announce();
    newZ3->announce();

    randomChump("zombie 5");
    
    delete newZ;
    delete newZ1;
    delete newZ2;
    delete newZ3;
    return 0;
}