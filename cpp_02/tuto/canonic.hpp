#ifndef CANONIC_HPP
#define CANONIC_HPP
#include <iostream>


class Sample
{
    public:
    Sample(void);
    Sample(int const n);
    Sample(Sample const & src);
    ~Sample(void);

    Sample & operator=(Sample const &rhs);
    int getFoo()const;

    private:

    int _foo;
};

std::ostream &operator<<(std::ostream &o, Sample const & i);
#endif




