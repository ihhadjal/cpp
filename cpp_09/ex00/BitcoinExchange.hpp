#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <fstream>
#include <stdlib.h> 
#include <limits.h>


class BTC
{
    private:
    std::vector<std::string> _vct;
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
    void    addVector(void);
    class ExceptionClass : public std::exception
    {
        private:
        const char *_msg;
        
        public:
        ExceptionClass(const char *msg);
        const char *what() const throw();
    };
    void    parse_date(BTC::ExceptionClass parse_exception);
    void    parse_value(BTC::ExceptionClass parse_exception);
    std::string    getDate(void);
    std::string    getValue(void);
};
#endif