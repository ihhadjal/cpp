#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <ostream>

class Harl
{ 
    private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);

    public:
    void    complain(std::string level);
};
#endif