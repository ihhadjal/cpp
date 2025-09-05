#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    BTC exchange;

    if (argc == 2)
    {
        try
        {
            exchange.addVector();
            exchange.parse(argv[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    else
        std::cout << "Error: could not open file" << '\n';
}