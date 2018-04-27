#ifndef FISHER_YATES_HPP
#define FISHER_YATES_HPP

#include <algorithm>
#include <cstdlib>
#include <functional>

namespace cgn {
    /*
    Fisher-Yates shuffle
    -------------------
    Randomly permutes a sequence with an equal probablity of every possible
    permutation.

    https://en.wikipedia.org/wiki/Fisher–Yates_shuffle

    Time complexity
    ---------------
    O(n), where n is the number of elements

    Space complexity
    ----------------
    O(1)
    */
    template <class RandomIt>
    void fisher_yates(RandomIt begin, RandomIt end, std::function<int()> random = rand) {
        if(begin >= end)
            return;

        for(auto i = --end; i > begin; --i) {
            auto j = begin + random() % (i - begin + 1);
            std::swap(*i, *j);
        }
    }
}

#endif
