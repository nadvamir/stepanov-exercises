#include "quicksort.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <chrono>

const int COL_W = 8;
const int FIRST_COL_W = 12;
const size_t MIN_SIZE = 8;
const size_t MAX_SIZE = 16 * 1024 * 1024;

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
        sort(buffer, buffer + size);

        if (!std::is_sorted(buffer, buffer + size)) {
            std::cerr << "*** SORT FAILED! ***" << std::endl;
            return 0;
        }

        first += size;
    }

    return t.stop();
}

template <typename T>
void print_cell(const T& x, int precision = 0)
{
    std::cout << std::setw(COL_W) << std::fixed
              << std::setprecision(precision)
              << x;
}

int main()
{
    using namespace std;

    vector<int> v(MAX_SIZE);
    vector<int> tmp(MAX_SIZE);
    random_iota(begin(v), end(v));

    std::cout << std::setw(FIRST_COL_W + COL_W * 2 - 2) << "std sort"
              << std::setw(COL_W * 2) << "my sort"
              << "\n" << std::flush;
    std::cout << std::setw(FIRST_COL_W) << "size"
              << std::setw(COL_W) << "time"
              << std::setw(COL_W) << "lg2"
              << std::setw(COL_W) << "time"
              << std::setw(COL_W) << "lg2"
              << std::setw(COL_W) << "ratio"
              << "\n" << std::flush;

    size_t lg = 3;
    for (size_t size = MIN_SIZE; size <= MAX_SIZE; size *= 2) {
        std::cout << std::setw(FIRST_COL_W) << size;

        double t = time_sort(
            [](auto b, auto e) { std::sort(b, e); },
            begin(v),
            end(v),
            begin(tmp),
            size);
        print_cell(t / MAX_SIZE);
        print_cell(t / MAX_SIZE / lg);

        double t2 = time_sort(
            [](auto b, auto e) { quick_sort(b, e); },
            begin(v),
            end(v),
            begin(tmp),
            size);
        print_cell(t2 / MAX_SIZE);
        print_cell(t2 / MAX_SIZE / lg);

        print_cell(t2 / t, 2);
        std::cout << "\n" << std::flush;

        ++lg;
    }
}

