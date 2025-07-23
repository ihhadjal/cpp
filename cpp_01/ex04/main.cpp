#include "replace.hpp"

int main(int argc, char **argv)
{
    parsing(argc, argv);
    Swap obj(argv[2], argv[3]);

    obj.replace(argv[1]);
}

void    parsing(int argc, char **argv)
{
    if (argc != 4 || !argv[1] || !argv[2] || !argv[3])
    {
        std::cout << "arguments error\n";
        exit (1);
    }
}