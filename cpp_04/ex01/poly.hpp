#ifndef POLY_HPP
#define POLY_HPP

#include <iostream>
#include <stdlib.h> 


class Animal
{   
    protected:
    std::string _type;

    public:
    Animal();
    Animal(const Animal &src);
    Animal &operator=(const Animal &rhs);
    Animal(std::string type);
    virtual ~Animal();
    virtual void makeSound()const;
    std::string getType() const;
};

class Dog : public Animal
{
    public:
    Dog();
    Dog(const Dog &src);
    Dog &operator=(const Dog &rhs);
    ~Dog();
    void makeSound()const;
};

class Cat : public Animal
{
    public:
    Cat();
    Cat(const Cat &src);
    Cat &operator=(const Cat &rhs);
    ~Cat();
    virtual void makeSound()const;
};

#endif