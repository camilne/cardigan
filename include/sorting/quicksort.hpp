#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <algorithm>
#include <cstdlib>
#include <iterator>

namespace cgn {
    namespace {
        template <class RandomIt, class Compare>
        RandomIt partition(RandomIt begin, RandomIt end, Compare compare) {
            auto pivot = *(begin + rand() % (end - begin));
            auto i = begin - 1;
            auto j = end + 1;
            while(true) {
                while(compare(*(++i), pivot))
                    ;
                while(compare(pivot, *(--j)))
                    ;
                if(i >= j)
                    return j;
                std::swap(*i, *j);
            }
        }
    }

    /*
    Quicksort
    -------------------
    Sort a container through divide and conquer. For each recursion, choose a
    pivot. This algorithm uses a random element from the block as the pivot.
    Then, the elements in the block are sorted such that each element on the
    left of the pivot is ordered before the pivot, and each element after the
    pivot is ordered after.

    Time complexity
    ---------------
    Best case: O(n log n), where n is the number of elemeents
    Average case: O(n log n)
    Worst case: O(n^2) -- this is extremely unlikely since the pivots are
    randomly chosen

    Space complexity
    ----------------
    O(n), where n is the number of recursions.
        - TODO: Optimize this to use O(log n) space by implementing Sedgewick's
          optimization to first recurse on the smaller partition, then use
          tail-call recursion on the other.
    */
    template <class RandomIt, class Compare>
    void quicksort(RandomIt begin, RandomIt end, Compare compare) {
        if(begin < end) {
            auto p = cgn::partition(begin, end, compare);
            quicksort(begin, p, compare);
            quicksort(p + 1, end, compare);
        }
    }

    template <class RandomIt>
    void quicksort(RandomIt begin, RandomIt end) {
        quicksort(begin, end, [](auto a, auto b) { return a < b; });
    }
}

#endif
