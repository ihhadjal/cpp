#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    Sort    algo;

    if (argc > 2)
    {
        algo.parse(argv);
    }
    else
        std::cout << "Error: not enough arguments\n";
}