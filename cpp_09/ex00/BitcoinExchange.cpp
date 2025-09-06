#include "BitcoinExchange.hpp"

BTC::BTC(){}
BTC::BTC(const BTC &src){
    *this = src;
}
BTC::~BTC(){}
BTC &BTC::operator=(const BTC &rhs){
    if (this != &rhs){
        this->_map = rhs._map;
        this->date = rhs.date;
        this->value = rhs.value;
        this->vctValue = rhs.vctValue;
        this->vctDate = rhs.vctDate;
    }
    return *this;
}

std::string BTC::getDate(){return this->date;}
std::string BTC::getValue(){return this->value;}

void        BTC::parse(char *argv)
{
    std::ifstream inFile;
    std::string   line;

    inFile.open(argv, std::fstream::in | std::ifstream::out);
    if (!inFile)
        std::cout << "Error: could not open file\n";
    while (getline(inFile, line))
    {
        if (line.find('|') == std::string::npos)
            std::cout << "invalid line '|' is missing\n";
        try
        {
            date = line.substr(0, line.find('|') - 1);
            value = line.substr(line.find('|') + 2, line.size());
            if (parse_date() == 0 && parse_value() == 0)
            {
                std::cout << date << " => " << value << " = " 
                << this->_map[date] * atof(value.c_str()) << '\n';
            }
        }
        catch(...){
            std::cout << "Error: can not accept empty values" << '\n';
        }
    }
}

int    BTC::parse_date()
{
    std::string year;
    std::string month;
    std::string day;

    year = date.substr(0, date.find('-'));
    month = date.substr(date.find('-') + 1, 2);
    day = date.substr(8, date.size());
    if (year.size() != 4 || month.size() != 2 || day.size() != 2
        || atoi(year.c_str()) > 2025 || atoi(month.c_str()) > 12 || atoi(day.c_str()) > 31)
    {
        std::cout << "Error: invalid date => " << this->date << '\n';
        return 1;
    }
    for (int i = 0; date[i]; i++)
    {
        if (!isdigit(date[i]) && date[i] != '\0' 
            && date[i] != '\n' && date[i] != ' ' && date[i] != '-')
        {
            std::cout << "Error: invalid date => " << this->date << '\n';
            return 1;
        }
    }
    return 0;
}

int    BTC::parse_value()
{
    if (value.empty()) {
        std::cout << "Error: can not accept empty values" << '\n';
        return 1;
    }
    for (size_t i = 0; i < value.size(); ++i)
    {
        if (!isdigit(value[i]) && value[i] != '.')
        {
            std::cout << "Error: invalid character => " << value[i] << '\n';
            return 1;
        }
    }
    if (value.size() >= 10)
    {
        std::cout << "Error: too large a number\n";
        return 1;
    }
    return 0;
}

void    BTC::addMap()
{
    std::ifstream inFile;
    std::string   line;

    inFile.open("DATA/data.csv");
    if (!inFile)
        std::cout << "Error: DB file is not accessible\n";
    while (getline(inFile, line))
    {
        int pos = line.find(',');
        this->vctDate = line.substr(0, pos);
        this->vctValue = line.substr(pos + 1, line.size());
        this->_map[this->vctDate] = atof(this->vctValue.c_str());
    }
}