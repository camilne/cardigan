#include <cstdlib>
#include <numeric>
#include <set>
#include <vector>

#include "third_party/catch.hpp"
#include "permute/fisher_yates.hpp"

using namespace cgn;

TEST_CASE("Fisher-Yates: Base case", "[fisher-yates]") {
    std::vector<int> values = {};
    fisher_yates(values.begin(), values.end());
    REQUIRE(values == std::vector<int>({}));

    values = {0};
    fisher_yates(values.begin(), values.end());
    REQUIRE(values == std::vector<int>({0}));
}

TEST_CASE("Fisher-Yates: Integer cases", "[fisher-yates]") {
    // https://en.wikipedia.org/wiki/Fisher-Yates_shuffle#Examples
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8};
    auto random = []() {
        static auto i = 0;
        std::vector<int> arr = {5, 1, 5, 0, 2, 2, 0};
        if(i >= (int)arr.size())
            i = 0;
        return arr[i++];
    };
    fisher_yates(values.begin(), values.end(), random);
    std::vector<int> permuted = {7, 5, 4, 3, 1, 8, 2, 6};
    REQUIRE(values == permuted);
}

TEST_CASE("Fisher-Yates: Doesn't remove or duplate elements", "[fisher-yates]") {
    srand(0);
    for(auto i = 0; i < 1000; ++i) {
        std::vector<int> values(1000);
        std::iota(values.begin(), values.end(), 0);

        fisher_yates(values.begin(), values.end());

        std::set<int> s(values.begin(), values.end());
        REQUIRE(values.size() == s.size());
    }
}
