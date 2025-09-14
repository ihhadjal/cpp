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

    if (cont.size() == 2)
    {
        if (cont[0] > cont[1])
            std::swap(cont[0], cont[1]);
        return;
    }
    typename Container::value_type Odd = 0;
    bool hasOdd = (cont.size() % 2 == 1);
    if (hasOdd)
        Odd = cont.back();
    typedef std::pair<typename Container::value_type, typename Container::value_type> Pair;
    std::vector<Pair> pairs;

    for (size_t i = 0; i + 1 < cont.size(); i += 2)
    {
        if (cont[i] <= cont[i + 1])
            pairs.push_back(std::make_pair(cont[i], cont[i + 1]));
        else
            pairs.push_back(std::make_pair(cont[i + 1], cont[i]));
    }
    Container largers;
    for (size_t i = 0; i < pairs.size(); ++i)
        largers.push_back(pairs[i].second);

    fordJohnson(largers);
    std::vector<Pair> sortedPairs;
    std::vector<bool> used(pairs.size(), false);

    for (size_t i = 0; i < largers.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (!used[j] && pairs[j].second == largers[i])
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }
    Container result;
    std::vector<typename Container::value_type> pendingSmalls;

    if (!sortedPairs.empty())
    {
        result.push_back(sortedPairs[0].first);
        for (size_t i = 0; i < sortedPairs.size(); ++i)
            result.push_back(sortedPairs[i].second);
        for (size_t i = 1; i < sortedPairs.size(); ++i)
            pendingSmalls.push_back(sortedPairs[i].first);
    }
    if (!pendingSmalls.empty())
    {
        std::vector<int> jacobsthal = generateJacobsthalSequence(pendingSmalls.size());
        std::vector<bool> inserted(pendingSmalls.size(), false);
        for (size_t i = 0; i < jacobsthal.size(); ++i)
        {
            int idx = jacobsthal[i] - 1;
            if (idx >= 0 && idx < static_cast<int>(pendingSmalls.size()) && !inserted[idx])
            {
                typename Container::value_type val = pendingSmalls[idx];
                size_t largePos = 0;
                for (size_t j = 0; j < result.size(); ++j)
                {
                    if (result[j] == sortedPairs[idx + 1].second)
                    {
                        largePos = j;
                        break;
                    }
                }
                typename Container::iterator pos = std::lower_bound(
                    result.begin(),
                    result.begin() + largePos + 1,
                    val);
                result.insert(pos, val);
                inserted[idx] = true;
            }
        }
        for (size_t i = 0; i < pendingSmalls.size(); ++i)
        {
            if (!inserted[i])
            {
                typename Container::value_type val = pendingSmalls[i];
                size_t largePos = 0;
                for (size_t j = 0; j < result.size(); ++j)
                {
                    if (result[j] == sortedPairs[i + 1].second)
                    {
                        largePos = j;
                        break;
                    }
                }
                typename Container::iterator pos = std::lower_bound(
                    result.begin(),
                    result.begin() + largePos + 1,
                    val);
                result.insert(pos, val);
            }
        }
    }
    if (hasOdd)
    {
        typename Container::iterator pos = std::lower_bound(result.begin(), result.end(), Odd);
        result.insert(pos, Odd);
    }
    cont = result;
}
#endif