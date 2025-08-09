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

class WrongAnimal
{
    protected:
    std::string _type;

    public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &src);
    WrongAnimal &operator=(const WrongAnimal &rhs);
    ~WrongAnimal();
    void    makeSound()const;
    std::string getType()const;
};

class WrongCat : public WrongAnimal
{
    public:
    WrongCat();
    WrongCat(const WrongCat &src);
    WrongCat &operator=(const WrongCat &rhs);
    ~WrongCat();
    void    makeSound()const;
};
#endif