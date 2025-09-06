#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    BTC exchange;

    if (argc == 2)
    {
        exchange.addMap();
        exchange.parse(argv[1]);
    }
    else
        std::cout << "Error: could not open file" << '\n';
}