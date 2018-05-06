#ifndef LONGEST_COMMON_SUBSTRING_HPP
#define LONGEST_COMMON_SUBSTRING_HPP

#include <vector>

namespace cgn {
    /*
    Longest common substring
    -------------------
    Find the longest consecutive substring that is common between two input
    strings (or ordered containers).

    Time complexity
    ---------------
    O(nr), where n and r are the lengths of the strings.

    Space complexity
    ----------------
    O(nr), where n and r are the lengths of the strings.
    */
    template <class RandomIt>
    std::vector<std::pair<RandomIt, RandomIt>> longest_common_substring(RandomIt first_begin,
        RandomIt first_end, RandomIt second_begin, RandomIt second_end) {
        auto first_length = first_end - first_begin;
        auto second_length = second_end - second_begin;

        std::vector<std::vector<int>> matrix(first_length);
        for(auto it = matrix.begin(); it != matrix.end(); ++it) {
            it->resize(second_length);
        }

        auto length = 0;
        std::vector<int> ret_sets;

        for(auto i = 0; i < first_length; ++i) {
            for(auto j = 0; j < second_length; ++j) {
                if(*(first_begin + i) == *(second_begin + j)) {
                    if(i == 0 || j == 0) {
                        matrix[i][j] = 1;
                    } else {
                        matrix[i][j] = matrix[i - 1][j - 1] + 1;
                    }

                    if(matrix[i][j] > length) {
                        length = matrix[i][j];
                        ret_sets = {i};
                    } else if(matrix[i][j] == length) {
                        ret_sets.push_back(i);
                    }
                } else {
                    matrix[i][j] = 0;
                }
            }
        }

        std::vector<std::pair<RandomIt, RandomIt>> results;
        for(auto&& ret : ret_sets) {
            results.push_back(std::make_pair(first_begin + ret - length + 1, first_begin + ret + 1));
        }

        return results;
    }

    std::vector<std::string> longest_common_substring(const std::string& first, const std::string& second) {
        auto pairs = longest_common_substring(first.begin(), first.end(), second.begin(), second.end());
        std::vector<std::string> results;
        for(auto&& pair : pairs) {
            results.push_back(std::string(pair.first, pair.second));
        }
        return results;
    }
}

#endif
