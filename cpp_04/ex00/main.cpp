#include "poly.hpp"

int main()
{
    const WrongAnimal *meta = new WrongAnimal();
    const Animal *j = new Dog();
    const WrongAnimal *i = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    // const WrongAnimal *meta = new WrongAnimal();
    // const Animal *j = new Dog();
    // const WrongAnimal *i = new WrongCat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound();
    // j->makeSound();
    // meta->makeSound();

    // delete meta;
    // delete j;
    // delete i;
}