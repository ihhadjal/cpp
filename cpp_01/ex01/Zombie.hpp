#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>

class Zombie{

    private:
    std::string m_name;
    public:
    Zombie();
    ~Zombie();
    void    setName(std::string name);
    void    announce(void);
};

Zombie *zombieHorde(int N, std::string name);
#endif 