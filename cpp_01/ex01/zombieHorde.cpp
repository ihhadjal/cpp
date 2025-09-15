#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *newZ = new Zombie[N];
    for (int i = 0; i < N ; i++)
    {
        newZ[i].setName(name);
        newZ[i].announce();
    }
    return (newZ);
} 