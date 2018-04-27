#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <algorithm>

namespace cgn {
    /*
    Bubble sort
    -------------------
    Sorts a container by repeatedly swapping adjacent incorrect elements. Continues
    to sort while a swap is performed during a scan of the container.

    RandomIt must be an iterator that allows random access.

    Compare must implement a function, compare(a, b), such that the container is
    sorted when, for every element, compare(a_i, a_{i-1}), is false.

    Time complexity
    ---------------
    Best case: O(n), where n is the number of elements
    Average case: O(n^2)
    Worst case: O(n^2)

    Space complexity
    ----------------
    O(1)
    */
    template <class RandomIt, class Compare>
    void bubble_sort(RandomIt first, RandomIt last, Compare compare) {
        if(first == last)
            return;

        for(auto i = first + 1; i != last; ++i) {
            auto swapped = false;
            for(auto j = first + 1; j != last; ++j) {
                if(!compare(*(j - 1), *j)) {
                    swapped = true;
                    std::swap(*(j - 1), *j);
                }
            }
            if(!swapped)
                break;
        }
    }

    template <class RandomIt>
    void bubble_sort(RandomIt first, RandomIt last) {
        bubble_sort(first, last, [](auto a, auto b){ return a < b; });
    }
}

#endif
