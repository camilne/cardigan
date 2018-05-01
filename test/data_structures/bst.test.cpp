#include <vector>

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

TEST_CASE("BST: Find", "[bst]") {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(-2);
    bst.insert(0);
    bst.insert(4);
    bst.insert(12);
    bst.insert(20);
    bst.insert(14);

    REQUIRE(bst.find(10) == true);
    REQUIRE(bst.find(-2) == true);
    REQUIRE(bst.find(0) == true);
    REQUIRE(bst.find(4) == true);
    REQUIRE(bst.find(4) == true);
    REQUIRE(bst.find(12) == true);
    REQUIRE(bst.find(20) == true);
    REQUIRE(bst.find(14) == true);

    REQUIRE(bst.find(6) == false);
    REQUIRE(bst.find(30) == false);
    REQUIRE(bst.find(-20) == false);
}

TEST_CASE("BST: Remove", "[bst]") {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(-2);
    bst.insert(0);
    bst.insert(4);
    bst.insert(12);
    bst.insert(20);
    bst.insert(14);

    REQUIRE(bst.remove(4) == true);
    REQUIRE(bst.find(4) == false);
    REQUIRE(bst.remove(14) == true);
    REQUIRE(bst.remove(-2) == true);
    REQUIRE(bst.remove(-2) == false);
}

TEST_CASE("BST: Inorder empty", "[bst]") {
    BinarySearchTree<int> bst;
    bst.inorder([](auto&){});
}

TEST_CASE("BST: Inorder normal", "[bst]") {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(-2);
    bst.insert(0);
    bst.insert(4);
    bst.insert(12);

    std::vector<int> order;
    auto predicate = [&](int& element) {
        order.push_back(element);
    };

    bst.inorder(predicate);

    const std::vector<int> expectedOrder = {-2, 0, 4, 10, 12};

    REQUIRE(order == expectedOrder);
}
