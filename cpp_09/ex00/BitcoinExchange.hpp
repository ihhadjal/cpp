#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <fstream>

class BTC
{
    private:

    public:
    BTC();
    BTC(const BTC &src);
    ~BTC();
    BTC &operator=(const BTC &rhs);
    void    parse(char *argv);

    class ExceptionClass : public std::exception
    {
        private:
        const char *_msg;

        public:
        ExceptionClass(const char *msg);
        const char *what() const throw();
    };
};

void    parse_date(std::string date, BTC::ExceptionClass parse_exception);
void    parse_value(std::string value, BTC::ExceptionClass parse_exception);
#endif