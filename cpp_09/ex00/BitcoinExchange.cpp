#include "BitcoinExchange.hpp"

BTC::BTC(){}
BTC::BTC(const BTC &src){
    *this = src;
}
BTC::~BTC(){}
BTC &BTC::operator=(const BTC &rhs){
    if (this != &rhs){
        //nothing to copy
    }
    return *this;
}
BTC::ExceptionClass::ExceptionClass(const char *msg) : _msg(msg){}

const char *BTC::ExceptionClass::what() const throw(){
    return this->_msg;
}

std::string BTC::getDate(){return this->date;}
std::string BTC::getValue(){return this->value;}

void        BTC::parse(char *argv)
{
    BTC::ExceptionClass file_exception("Error: could not open file");
    BTC::ExceptionClass parse_exception("Error: parsing error");

    std::ifstream inFile;
    std::string   line;

    inFile.open(argv, std::fstream::in | std::ifstream::out);
    if (!inFile)
        throw file_exception;
    while (getline(inFile, line))
    {
        if (line.find('|') == std::string::npos)
            throw parse_exception;
        date = line.substr(0, line.find('|'));
        value = line.substr(line.find('|') + 2, line.size());
        parse_date(parse_exception);
        parse_value(parse_exception);
    }
}

void    BTC::parse_date(BTC::ExceptionClass parse_exception)
{
    std::string year;
    std::string month;
    std::string day;

    year = date.substr(0, date.find('-'));
    month = date.substr(date.find('-') + 1, 2);
    day = date.substr(8, date.size());

    if (year.size() != 4 || month.size() != 2 || day.size() != 3)
        throw parse_exception;
    for (int i = 0; date[i]; i++)
    {
        if (!isdigit(date[i]) && date[i] != '\0' 
            && date[i] != '\n' && date[i] != ' ' && date[i] != '-')
            throw parse_exception;
    }
}


void    BTC::parse_value(BTC::ExceptionClass parse_exception)
{
    for (int i = 0; value[i]; i++)
    {
        if ((!isdigit(value[i]) && value[i] != '.'))
            throw parse_exception;
    }
    if (value.size() >= 10)
    {
        std::cout << "Error: too large a number\n";
        exit (1);
    }
}

void    BTC::addVector()
{
    std::ifstream inFile;
    std::string   line;

    inFile.open("DATA/data.csv");
    if (!inFile)
        throw std::exception();
    while (getline(inFile, line))
        this->_vct.push_back(line);
}