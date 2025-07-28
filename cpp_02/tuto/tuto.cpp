#include "tuto.hpp"

Integer::Integer(int const n) : _n(n)
{
    std::cout << "Constructor called with value: " << n << std::endl;
}

Integer::~Integer()
{
    std::cout << "Destructor called with value: " << this->_n << std::endl;
}

int Integer::getValue() const
{
    return (this->_n);
}

Integer & Integer::operator=(Integer const &rhs)
{
    std::cout << "Assignation operator called from: " << this->_n;
    std::cout << " to " << rhs.getValue() << std::endl;

    this->_n = rhs.getValue();

    return *this;
}

Integer Integer::operator+(Integer const &rhs) const
{
    std::cout << "Addition operator called with: " << this->_n;
    std::cout << " and " << rhs.getValue() << std::endl;

    return Integer(this->_n + rhs.getValue());
}

std::ostream & operator<<(std::ostream &o, Integer const &rhs){
    o << rhs.getValue();
    return o;
}


int main()
{
    Integer iheb (10);
    Integer mew (20);
    Integer oe (0);

    std::cout << "the value of iheb is: " << iheb << std::endl;
    std::cout << "the value of mew is: " << mew << std::endl;
    iheb = Integer(40);
    std::cout << "the value of iheb is: " << iheb << std::endl;
    std::cout << "the value of oe is: " << oe << std::endl;
    oe = iheb + mew;
    std::cout << "the value of oe is: " << oe << std::endl;
}