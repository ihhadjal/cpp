#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}


// int main()
// {
//     MutantStack<int>mstack;
//     MutantStack<int>nstack;

//     std::cout << "---empty stack Test: ---\n";
//     if (mstack.empty())
//         std::cout << "Stack is empty\n";
//     else
//         std::cout << "Stack is not empty\n";
//     mstack.push(4);
//     mstack.push(6);
//     mstack.push(5);
//     std::cout << "---stack elements: ---\n";
//     for (MutantStack<int>::iterator::iterator it = mstack.begin(); it != mstack.end(); ++it)
//         std::cout << *it << '\n';
//     std::cout << "size: " << mstack.size() << '\n';
// }