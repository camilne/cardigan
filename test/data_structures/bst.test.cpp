#include "data_structures/bst.hpp"
#include "third_party/catch.hpp"

using namespace cgn;

TEST_CASE("BST: Empty", "[bst]") {
    BinarySearchTree<int> bst;
}

TEST_CASE("BST: Insert", "[bst]") {
    BinarySearchTree<int> bst;

    REQUIRE(bst.insert(12) == true);
    REQUIRE(bst.insert(10) == true);
    REQUIRE(bst.insert(-8) == true);
    REQUIRE(bst.insert(12) == false);
    REQUIRE(bst.insert(15) == true);
}
