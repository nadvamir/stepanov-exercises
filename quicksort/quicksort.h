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

    while (*first < pivot) ++first;
    while (pivot < *last) --last;

    while (first < last) {
        std::swap(*first, *last);
        ++first; --last;

        while (*first < pivot) ++first;
        while (pivot < *last) --last;
    }

    return first;
}

template<class It>
void insertion_sort(It first, It last)
{
    for (It i = first + 1; i < last; ++i) {
        auto element = *i;

        It j = i;
        for ( ; j != first && element < *(j - 1); --j) {
            *j = *(j - 1);
        }

        *j = element;
    }
}

template<class It>
void quick_sort_loop(It first, It last, size_t threshold)
{
    using namespace std;
    while (std::distance(first, last) > threshold) {
        It middle = first + (last - first) / 2;
        auto pivot = median(*first, *middle, *(last - 1));
        It mid = mypartition(first, last, pivot);

        if (mid - first < last - mid) {
            quick_sort_loop(first, mid, threshold);
            first = mid;
        }
        else {
            quick_sort_loop(mid, last, threshold);
            last = mid;
        }
    }
}

template<class It>
void quick_sort(It first, It last)
{
    const size_t threshold = 16;
    quick_sort_loop(first, last, threshold);
    insertion_sort(first, last);
}

#endif

