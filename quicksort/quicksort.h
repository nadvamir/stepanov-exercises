#ifndef INCLUDED_QUICKSORT
#define INCLUDED_QUICKSORT

#include <algorithm>

template<class Val>
Val median(Val a, Val b, Val c)
{
    if (a < c) {
        if (c < b) return c;
        if (a < b) return b;
        return a;
    }
    if (b < c) return c;
    if (a < b) return a;
    return b;
}

template<class It, class Val>
It mypartition(It first, It last, Val pivot)
{
    --last;

    while (first < last) {
        while (*first < pivot) ++first;
        while (pivot < *last) --last;

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
        It middle = first + (last - first) / 2;
        auto pivot = median(*first, *middle, *(last - 1));
        It mid = mypartition(first, last, pivot);

        if (mid - first < last - mid) {
            quickSort(first, mid);
            first = ++mid;
        }
        else {
            quickSort(mid + 1, last);
            last = mid;
        }
    }
    insertionSort(first, last);
}

#endif

