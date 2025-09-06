#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <map>
#include <exception>
#include <fstream>
#include <stdlib.h> 
#include <limits.h>
#include <string>
/*

map["date"] = atof(valeur);

date wanted =  first date

map[date_wanted] * valeur wanted
*/

class BTC
{
    private:
    std::map<std::string, float> _map;
    std::string   date;
    std::string   value;
    std::string   vctValue;
    std::string   vctDate;

    public:
    BTC();
    BTC(const BTC &src);
    ~BTC();
    BTC &operator=(const BTC &rhs);
    void    parse(char *argv);
    void    addMap(void);
    int    parse_date();
    int    parse_value();
    std::string    getDate(void);
    std::string    getValue(void);
};
#endif