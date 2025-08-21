#include "ScalarConvert.hpp"

int main(int argc, char **argv)
{
    // ScalarConvert *obj = NULL;

    if (argc == 2)
        ScalarConvert::convert(argv[1]);
    else
        std::cout << "error: to many arguments\n";
}
