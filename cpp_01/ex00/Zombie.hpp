#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>



class   Zombie{
    private:
    std::string m_name;

    public:
    Zombie(std::string name);
    ~Zombie();
    void    announce(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);
#endif