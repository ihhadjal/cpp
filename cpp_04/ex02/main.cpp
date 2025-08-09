#include "poly.hpp"

int main()
{
    const int N = 6;
    Animal *animals[N];

    for (int i = 0; i < N / 2; ++i)
        animals[i] = new Dog();
    for (int i = N / 2; i < N; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < N; ++i)
        animals[i]->makeSound();

    for (int i = 0; i < N; ++i)
        delete animals[i];
    return 0;
}