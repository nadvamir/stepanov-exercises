#ifndef INCLUDED_QUICKSORT
#define INCLUDED_QUICKSORT

#include <algorithm>

template<class It>
It median(It first, It last)
{
    It mid = first;
    std::advance(mid, std::distance(first, last) / 2);
    --last;

    if (*first < *last) {
        if (*last < *mid) return last;
        return *first < *mid ? mid : first;
    }
    else if (*last < *first) {
        if (*first < *mid) return first;
        return *last < *mid ? mid : last;
    }
    return *first < *mid ? first : mid;
}

template<class It>
It partition(It first, It last, It pivot)
{
    auto pivotValue = *pivot;
    --last;

    while (first < last) {
        while (*first < pivotValue) ++first;
        while (pivotValue < *last) --last;

        if (*first != *last) {
            std::swap(*first, *last);
        }
        else if (first < last) {
            ++first;
        }
    }

    return first;
}

template<class It>
void insertionSort(It first, It last)
{
    for (It i = first + 1; i < last; ++i) {
        for (It j = i; j != first && *j < *(j - 1); --j) {
            std::iter_swap(j, j - 1);
        }
    }
}

template<class It>
void quickSort(It first, It last)
{
    using namespace std;
    while (std::distance(first, last) > 16) {
        It pivot = median(first, last);
        pivot = partition(first, last, pivot);

        if (pivot - first < last - pivot) {
            quickSort(first, pivot);
            first = ++pivot;
        }
        else {
            quickSort(pivot + 1, last);
            last = pivot;
        }
    }
    insertionSort(first, last);
}

#endif
