#include "Zombie.hpp"

int main()
{
    Zombie *z = zombieHorde(15, "iheb");
    for (int i = 0; i < 15; i++)
        z[i].announce();
    delete [] z;
} 