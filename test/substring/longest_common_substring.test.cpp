#include <algorithm>
#include <vector>

#include "third_party/catch.hpp"
#include "substring/longest_common_substring.hpp"

using namespace cgn;

TEST_CASE("Longest Common Substring: Base cases", "[longest-common-substring]") {
    std::string a;
    auto substrings = longest_common_substring(a, a);

    REQUIRE(substrings.size() == 0);

    a = "a";
    substrings = longest_common_substring(a, a);

    REQUIRE(substrings.size() == 1);
    REQUIRE(substrings[0] == a);

    std::vector<int> b;
    auto b_substrings = longest_common_substring(b.begin(), b.end(), b.begin(), b.end());

    REQUIRE(b_substrings.size() == 0);

    b = {0};
    b_substrings = longest_common_substring(b.begin(), b.end(), b.begin(), b.end());

    REQUIRE(b_substrings.size() == 1);
    REQUIRE(b_substrings[0].first == b.begin());
    REQUIRE(b_substrings[0].second == b.end());
}

TEST_CASE("Longest Common Substring: String cases", "[longest-common-substring]") {
    std::string a = "asdfghjkl;";
    std::string b = "fghasdjlk;";
    auto substrings = longest_common_substring(a, b);

    REQUIRE(substrings.size() == 2);
    std::sort(substrings.begin(), substrings.end());
    REQUIRE(substrings[0] == "asd");
    REQUIRE(substrings[1] == "fgh");
}

TEST_CASE("Longest Common Substring: Container cases", "[longest-common-substring]") {
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> b = {3, 7, 4, 4, 3, 4, 5};
    auto substrings = longest_common_substring(a.begin(), a.end(), b.begin(), b.end());

    REQUIRE(substrings.size() == 1);
    REQUIRE(std::vector<int>(substrings[0].first, substrings[0].second) == std::vector<int>{3, 4, 5});
}
