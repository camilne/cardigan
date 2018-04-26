#include <vector>

#include "third_party/catch.hpp"
#include "sorting/quicksort.hpp"
#include "test/common.test.hpp"

using namespace cgn;

TEST_CASE("Quicksort: Base case", "[quicksort]") {
    std::vector<int> values = {};
    REQUIRE(does_sort(quicksort, values.begin(), values.end()));

    values = {0};
    REQUIRE(does_sort(quicksort, values.begin(), values.end()));
}

TEST_CASE("Quicksort: Non-descending integer", "[quicksort]") {
    std::vector<int> values = {5, 2, 8, -1, 3};
    REQUIRE(does_sort(quicksort, values.begin(), values.end()));

    values = {4, 8, 12, -5, -6};
    REQUIRE(does_sort(quicksort, values.begin(), values.end()));

    values = {5, 6, 6, 6, -2, 0, 0};
    REQUIRE(does_sort(quicksort, values.begin(), values.end()));
}

TEST_CASE("Quicksort: Non-ascending integer", "[quicksort]") {
    auto reverse = [](auto a, auto b) { return a > b; };

    std::vector<int> values = {5, 2, 8, -1, 3};
    REQUIRE(does_sort(quicksort, values.begin(), values.end(), reverse));

    values = {4, 8, 12, -5, -6};
    REQUIRE(does_sort(quicksort, values.begin(), values.end(), reverse));

    values = {5, 6, 6, 6, -2, 0, 0};
    REQUIRE(does_sort(quicksort, values.begin(), values.end(), reverse));
}

TEST_CASE("Quicksort: Floating point", "[quicksort]") {
    std::vector<float> values = {5.2, 2.7, 2.4, -1, 3};
    REQUIRE(does_sort(quicksort, values.begin(), values.end()));

    auto reverse = [](auto a, auto b) { return a > b; };
    values = {4.5, 8.2, 12.0, -5.2, -6.8};
    REQUIRE(does_sort(quicksort, values.begin(), values.end(), reverse));

    values = {5.1, 6.6, 6.7, 6.7, -2.3, 0.0, 0.0};
    REQUIRE(does_sort(quicksort, values.begin(), values.end()));
}
