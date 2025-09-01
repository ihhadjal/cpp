#include "Array.hpp"

int main(void)
{
    std::cout << "No parameters test: \n";
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << '\n';

    std::cout << "Test with parameters: \n";
    Array<int> intArray(5);
    std::cout << "Array size: " << intArray.size() << '\n';

    std::cout << "Default values:\n";
    for (unsigned int i = 0; i < intArray.size(); i++)
        std::cout << intArray[i] << " ";
    std::cout << '\n';
    for (unsigned int i = 0; i < intArray.size(); i++)
        intArray[i] = i * 10;
    std::cout << "Values after increase: \n";
    for (unsigned int i = 0; i < intArray.size(); i++)
        std::cout << intArray[i] << " ";
    std::cout << '\n';
    std::cout << "Copy constructor test:\n";
    Array<int> copyArray(intArray);
    std::cout << "Copy array size: " << copyArray.size() << '\n';
    std::cout << "Copied values: ";
    for (unsigned int i = 0; i < copyArray.size(); i++)
        std::cout << copyArray[i] << ' ';
    std::cout << '\n';
    std::cout << "Test with strings:\n";
    Array<std::string> stringArray(3);
    stringArray[0] = "Iheb";
    stringArray[1] = "le";
    stringArray[2] = "bogoss";
    for (unsigned int i = 0; i < stringArray.size(); i++)
        std::cout << stringArray[i] << ' ';
    std::cout << '\n';
    std::cout << "Exceptions tests:\n";
    try
    {
        std::cout << "Trying to acces the tenth index in an array of size: " << intArray.size() << std::endl;
        std::cout << intArray[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: index out of bounds" << std::endl;
    }
    try
    {
        std::cout << "Trying to access the index 0 of an empty array" << std::endl;
        std::cout << emptyArray[0] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: empty array" << std::endl;
    }
}