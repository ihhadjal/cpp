#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer default constructor called\n";
}

Serializer::~Serializer()
{
    std::cout << "Serializer destructor called\n";
}

Serializer::Serializer(const Serializer &src)
{
    *this = src;

    std::cout << "Serializer copy constructor called\n";
}

Serializer &Serializer::operator=(const Serializer &rhs)
{
    (void)rhs;
    // Serializer has no variables to copy;
    return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    std::cout << "Serialization done\n";
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    std::cout << "Deserialization done\n";
    return reinterpret_cast<Data *>(raw);
}