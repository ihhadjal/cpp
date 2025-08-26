#include "Serializer.hpp"

int main()
{
    Data dataBase(10, "iheb", 6.7);

    std::cout << "Original Data:" << '\n';
    std::cout << "id: " << dataBase._id << '\n';
    std::cout << "name: " << dataBase._name << '\n';
    std::cout << "value: " << dataBase._value << '\n';


    uintptr_t serializedData = Serializer::serialize(&dataBase);
    Data *deserializedData = Serializer::deserialize(serializedData);
    std::cout << "Data after deserialization: " << '\n';
    std::cout << "id: " << deserializedData->_id << '\n';
    std::cout << "name: " << deserializedData->_name << '\n';
    std::cout << "value: " << deserializedData->_value << '\n';

}