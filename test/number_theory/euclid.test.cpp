#include <stdexcept>

#include "number_theory/euclid.hpp"
#include "third_party/catch.hpp"

using namespace cgn;

TEST_CASE("Euclid GCD: Base case", "[euclid]") {
    REQUIRE(gcd_euclid(1, 1) == 1);
}

TEST_CASE("Euclid GCD: Invalid cases", "[euclid]") {
    REQUIRE_THROWS_AS(gcd_euclid(1, 0), std::invalid_argument);
    REQUIRE_THROWS_AS(gcd_euclid(0, 1), std::invalid_argument);
    REQUIRE_THROWS_AS(gcd_euclid(0, 0), std::invalid_argument);
    REQUIRE_THROWS_AS(gcd_euclid(-1, 1), std::invalid_argument);
    REQUIRE_THROWS_AS(gcd_euclid(1, -1), std::invalid_argument);
}

TEST_CASE("Euclid GCD: Normal cases", "[euclid]") {
    REQUIRE(gcd_euclid(10, 2) == 2);
    REQUIRE(gcd_euclid(10, 6) == 2);
    REQUIRE(gcd_euclid(12, 6) == 6);
    REQUIRE(gcd_euclid(12, 20) == 4);
    REQUIRE(gcd_euclid(13, 20) == 1);
    REQUIRE(gcd_euclid(13, 13) == 13);
}
