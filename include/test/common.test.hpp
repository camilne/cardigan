#ifndef SORTING_COMMON_TEST_HPP
#define SORTING_COMMON_TEST_HPP

#include <functional>

template <class RandomIt, class Compare>
bool does_sort(void (*sorting_function)(RandomIt, RandomIt, Compare),
                RandomIt first, RandomIt last, Compare compare) {
    sorting_function(first, last, compare);
    return std::is_sorted(first, last, compare);
}

template <class RandomIt>
bool does_sort(void (*sorting_function)(RandomIt, RandomIt), RandomIt first,
                RandomIt last) {
    sorting_function(first, last);
    return std::is_sorted(first, last);
}

#endif
