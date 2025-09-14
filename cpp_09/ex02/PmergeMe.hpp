#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <typeinfo>

class Sort
{
private:
    std::vector<unsigned int> _vct;
    std::deque<unsigned int> _lst;
    int count;

    template <typename Container>
    void fordJohnson(Container &cont);

    template <typename Container>
    typename Container::iterator binarySearch(Container &cont,
                                              typename Container::iterator begin,
                                              typename Container::iterator end,
                                              const typename Container::value_type &value);

    std::vector<int> generateJacobsthalSequence(int n);

public:
    Sort();
    Sort(const Sort &src);
    ~Sort();
    Sort &operator=(const Sort &rhs);
    void parseAndInit(char **argv);
    void mergeSort(char **argv);

    template <typename Container>
    void sort(Container &cont);
};

template <typename Container>
void printContainer(Container &cont)
{
    typename Container::iterator it;
    for (it = cont.begin(); it != cont.end(); ++it)
        std::cout << *it << ' ';
    std::cout << '\n';
}
template <typename Container>
void checkSort(Container &cont)
{
    if (cont.empty())
    {
        std::cout << "Container is empty\n";
        return;
    }

    typename Container::iterator it = cont.begin();
    typename Container::iterator next = it;
    ++next;

    for (; next != cont.end(); ++it, ++next)
    {
        if (*it > *next)
        {
            std::cout << "Error: the container is not sorted\n";
            return;
        }
    }
    std::cout << "Everything is ok the container is sorted\n";
}

template <typename Container>
void Sort::sort(Container &cont)
{
    if (cont.size() <= 1)
        return;
    clock_t start = clock();
    fordJohnson(cont);
    clock_t end = clock();
    if (count == 0)
    {
        std::cout << "After: ";
        printContainer(cont);
    }
    count++;
    double time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000;
    if (typeid(Container) == typeid(std::vector<unsigned int>))
        std::cout << "Time to process a range of " << cont.size() << " elements with std::vector : " << time << " us" << std::endl;
    else
        std::cout << "Time to process a range of " << cont.size() << " elements with std::deque : " << time << " us" << std::endl;
}

template <typename Container>
void Sort::fordJohnson(Container &cont)
{
    if (cont.size() <= 1)
        return;

    std::vector<std::pair<typename Container::value_type, typename Container::value_type> > pairs;
    typename Container::value_type Odd = 0;
    bool hasOdd = false;

    for (size_t i = 0; i < cont.size(); i += 2)
    {
        if (i + 1 < cont.size())
        {
            typename Container::value_type a = cont[i];
            typename Container::value_type b = cont[i + 1];
            if (a > b)
                pairs.push_back(std::make_pair(b, a));
            else
                pairs.push_back(std::make_pair(a, b));
        }
        else
        {
            Odd = cont[i];
            hasOdd = true;
        }
    }

    Container largerElements;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        largerElements.push_back(pairs[i].second);
    }

    if (largerElements.size() > 1)
        fordJohnson(largerElements);

    Container result;

    if (!pairs.empty())
        result.push_back(pairs[0].first);

    for (typename Container::iterator it = largerElements.begin(); it != largerElements.end(); ++it)
        result.push_back(*it);

    std::vector<int> jacobsthal = generateJacobsthalSequence(pairs.size());
    std::vector<bool> inserted(pairs.size(), false);

    if (!pairs.empty())
        inserted[0] = true;

    for (size_t i = 0; i < jacobsthal.size(); ++i)
    {
        int idx = jacobsthal[i] - 1;
        if (idx >= 0 && idx < static_cast<int>(pairs.size()) && !inserted[idx])
        {
            typename Container::value_type valueToInsert = pairs[idx].first;
            typename Container::iterator pos = binarySearch(result, result.begin(), result.end(), valueToInsert);
            result.insert(pos, valueToInsert);
            inserted[idx] = true;
        }
    }

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (!inserted[i])
        {
            typename Container::value_type valueToInsert = pairs[i].first;
            typename Container::iterator pos = binarySearch(result, result.begin(), result.end(), valueToInsert);
            result.insert(pos, valueToInsert);
        }
    }

    if (hasOdd)
    {
        typename Container::iterator pos = binarySearch(result, result.begin(), result.end(), Odd);
        result.insert(pos, Odd);
    }

    cont = result;
}

template <typename Container>
typename Container::iterator Sort::binarySearch(Container &,
                                                typename Container::iterator begin,
                                                typename Container::iterator end,
                                                const typename Container::value_type &value)
{
    typename Container::iterator left = begin;
    typename Container::iterator right = end;

    while (left != right)
    {
        typename Container::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        if (*mid < value)
            left = ++mid;
        else
            right = mid;
    }

    return left;
}

#endif