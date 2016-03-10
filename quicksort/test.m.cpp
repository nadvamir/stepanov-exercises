#include "quicksort.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <chrono>

using namespace std;

class Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
public:
    void start()
    {
        start_time = std::chrono::high_resolution_clock::now();
    }

    double stop()
    {
        auto stop_time = std::chrono::high_resolution_clock::now();
        return double(std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - start_time).count());
    }
};

template<class It>
void random_iota(It first, It last)
{
  iota(first, last, 0);
  random_shuffle(first, last);
}

template <class Sort, class It>
double time_sort(
    Sort sort,
    It first,
    It last,
    It buffer,
    size_t size) 
{
    Timer t;
    t.start();
    while (size <= last - first) {
        std::copy(first, first + size, buffer);
        first += size;
        sort(buffer, buffer + size);
        if (!std::is_sorted(buffer, buffer + size)) {
            std::cerr << "*** SORT FAILED! ***" << std::endl;
            return 0;
        }
    }
    return t.stop();
}

template <typename T>
void print_cell(const T& x, int precision = 0) {
    std::cout << "\t" << std::setw(6)
              << std::fixed << std::setprecision(precision)
              << x;
}

int main()
{
    const size_t minSize = 8;
    const size_t maxSize = 16 * 1024 * 1024;

    vector<int> v(maxSize);
    vector<int> tmp(maxSize);
    random_iota(begin(v), end(v));

    std::cout << std::setw(13) << "size\t" << std::setw(6) << "std\t"
              << std::setw(6) << "my\t" << std::setw(6) << "ratio"
              << "\n" << std::flush;
    for (size_t size = minSize; size <= maxSize; size *= 2) {
        std::cout << std::setw(12) << size;
        double t = time_sort(
            [](auto b, auto e) { std::sort(b, e); },
            begin(v),
            end(v),
            begin(tmp),
            size);
        print_cell(t / maxSize);

        double t2 = time_sort(
            [](auto b, auto e) { quick_sort(b, e); },
            begin(v),
            end(v),
            begin(tmp),
            size);
        print_cell(t2 / maxSize);

        print_cell(t2 / t, 2);
        std::cout << "\n" << std::flush;
    }
}

