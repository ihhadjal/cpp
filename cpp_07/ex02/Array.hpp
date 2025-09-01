#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <iostream>
#include <exception>

template<typename T>

class Array
{
    private:
    T *_elements;
    unsigned int _size;

    public:
    Array() : _elements(NULL), _size(0){} // default constructor creates an empty array

    Array(unsigned int n) : _elements(new T[n]()), _size(n){} // unsigned int constructor, creates n elements

    Array(const Array &src) : _elements(NULL), _size(0){ // copy constructor
        *this = src;
    }

    Array &operator=(const Array &rhs){ // assignement operator, we free the previous elements of the array and we copy the new ones with a hard copy
        if (this != &rhs)
        {
            delete [] _elements;
            _size = rhs._size;
            if (_size > 0)
            {
                _elements = new T[_size];
                for (unsigned int i = 0; i < _size; i++){
                    _elements[i] = rhs._elements[i];
                }
            }
            else
                _elements = NULL;
        }
        return (*this);
    }

    ~Array(){ // destructor
        delete [] _elements;
    }


    T &operator[](unsigned int index){ // subscription operator with limits verifications
        if (index >= _size)
            throw std::exception();
        return _elements[index];
    }

    unsigned int size() const{ // size function that returns the number of elements
        return _size;
    }
};


#endif