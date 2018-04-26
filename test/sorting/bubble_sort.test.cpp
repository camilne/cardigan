#include <vector>

#include "third_party/catch.hpp"
#include "sorting/bubble_sort.hpp"
#include "test/common.test.hpp"

TEST_CASE("Bubble sort: Base case", "[bubble sort]") {
    std::vector<int> values = {};
    REQUIRE(does_sort(bubble_sort, values.begin(), values.end()));

    values = {0};
    REQUIRE(does_sort(bubble_sort, values.begin(), values.end()));
}

TEST_CASE("Bubble sort: Non-descending integer", "[bubble sort]") {
    std::vector<int> values = {5, 2, 8, -1, 3};
    REQUIRE(does_sort(bubble_sort, values.begin(), values.end()));

    values = {4, 8, 12, -5, -6};
    REQUIRE(does_sort(bubble_sort, values.begin(), values.end()));

    values = {5, 6, 6, 6, -2, 0, 0};
    REQUIRE(does_sort(bubble_sort, values.begin(), values.end()));
}

TEST_CASE("Bubble sort: Non-ascending integer", "[bubble sort]") {
    auto reverse = [](auto a, auto b) { return a > b; };

    std::vector<int> values = {5, 2, 8, -1, 3};
    REQUIRE(does_sort(bubble_sort, values.begin(), values.end(), reverse));

    values = {4, 8, 12, -5, -6};
    REQUIRE(does_sort(bubble_sort, values.begin(), values.end(), reverse));

    values = {5, 6, 6, 6, -2, 0, 0};
    REQUIRE(does_sort(bubble_sort, values.begin(), values.end(), reverse));
}

TEST_CASE("Bubble sort: Floating point", "[bubble sort]") {
    std::vector<float> values = {5.2, 2.7, 2.4, -1, 3};
    REQUIRE(does_sort(bubble_sort, values.begin(), values.end()));

    auto reverse = [](auto a, auto b) { return a > b; };
    values = {4.5, 8.2, 12.0, -5.2, -6.8};
    REQUIRE(does_sort(bubble_sort, values.begin(), values.end(), reverse));

    values = {5.1, 6.6, 6.7, 6.7, -2.3, 0.0, 0.0};
    REQUIRE(does_sort(bubble_sort, values.begin(), values.end()));
}
