#include <iostream>

template<typename T>

class list
{
    public:
    list<T>(T const &content){
        //...
    }
    list<T>(list<T> const &list){
        //...
    }
    list<T>(void){
        //...
    }

    private:
    T   *_content;
    list<T> *_next; 

};

int main()
{
    list<int> a(42);
    list<float> b(42.2f);
    list<list<int>> c (a);
}