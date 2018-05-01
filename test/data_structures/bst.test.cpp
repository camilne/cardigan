#include <string>
#include <vector>

#include "data_structures/bst.hpp"
#include "third_party/catch.hpp"

using namespace cgn;

TEST_CASE("BST: Empty", "[bst]") {
    BinarySearchTree<int, int> bst;
}

TEST_CASE("BST: Insert", "[bst]") {
    BinarySearchTree<int, int> bst;

    REQUIRE(bst.insert(12, 24) == true);
    REQUIRE(bst.insert(10, 0) == true);
    REQUIRE(bst.insert(-8, 0) == true);
    REQUIRE(bst.insert(12, 14) == false);
    REQUIRE(bst.insert(15, 20) == true);
}

TEST_CASE("BST: Find", "[bst]") {
    BinarySearchTree<int, int> bst;
    bst.insert(10, 20);
    bst.insert(-2, 12);
    bst.insert(0, 4);
    bst.insert(4, 8);
    bst.insert(12, 104);
    bst.insert(20, 43);
    bst.insert(14, 45);

    REQUIRE(bst.find(10));
    REQUIRE(*bst.find(10) == 20);
    REQUIRE(bst.find(-2));
    REQUIRE(*bst.find(-2) == 12);
    REQUIRE(bst.find(0));
    REQUIRE(*bst.find(0) == 4);
    REQUIRE(bst.find(4));
    REQUIRE(*bst.find(4) == 8);
    REQUIRE(bst.find(4));
    REQUIRE(*bst.find(4) == 8);
    REQUIRE(bst.find(12));
    REQUIRE(*bst.find(12) == 104);
    REQUIRE(bst.find(20));
    REQUIRE(*bst.find(20) == 43);
    REQUIRE(bst.find(14));
    REQUIRE(*bst.find(14) == 45);

    REQUIRE(!bst.find(6));
    REQUIRE(!bst.find(30));
    REQUIRE(!bst.find(-20));
}

TEST_CASE("BST: Remove", "[bst]") {
    BinarySearchTree<int, int> bst;
    bst.insert(10, 8);
    bst.insert(-2, 7);
    bst.insert(0, 5);
    bst.insert(4, 10);
    bst.insert(12, 9);
    bst.insert(20, 12);
    bst.insert(14, 15);

    REQUIRE(bst.remove(4) == true);
    REQUIRE(!bst.find(4));
    REQUIRE(bst.remove(14) == true);
    REQUIRE(bst.remove(-2) == true);
    REQUIRE(bst.remove(-2) == false);
}

TEST_CASE("BST: Inorder empty", "[bst]") {
    BinarySearchTree<int, int> bst;
    bst.inorder([](auto&, auto&){});
}

TEST_CASE("BST: Inorder normal", "[bst]") {
    BinarySearchTree<int, int> bst;
    bst.insert(10, 1);
    bst.insert(-2, 1);
    bst.insert(0, 1);
    bst.insert(4, 1);
    bst.insert(12, 1);

    std::vector<int> order;
    auto sum = 0;
    auto predicate = [&](int& element, int& data) {
        order.push_back(element);
        sum += data;
    };

    bst.inorder(predicate);

    const std::vector<int> expectedOrder = {-2, 0, 4, 10, 12};

    REQUIRE(order == expectedOrder);
    REQUIRE(sum == 5);
}

TEST_CASE("BST: Postorder empty", "[bst]") {
    BinarySearchTree<int, int> bst;
    bst.postorder([](auto&, auto&){});
}

TEST_CASE("BST: Postorder normal", "[bst]") {
    BinarySearchTree<int, int> bst;
    bst.insert(10, 1);
    bst.insert(-2, 1);
    bst.insert(0, 1);
    bst.insert(4, 1);
    bst.insert(12, 1);

    std::vector<int> order;
    auto sum = 0;
    auto predicate = [&](int& element, int& data) {
        order.push_back(element);
        sum += data;
    };

    bst.postorder(predicate);

    const std::vector<int> expectedOrder = {4, 0, -2, 12, 10};

    REQUIRE(order == expectedOrder);
    REQUIRE(sum == 5);
}

TEST_CASE("BST: Preorder empty", "[bst]") {
    BinarySearchTree<int, int> bst;
    bst.preorder([](auto&, auto&){});
}

TEST_CASE("BST: Preorder normal", "[bst]") {
    BinarySearchTree<int, int> bst;
    bst.insert(10, 1);
    bst.insert(-2, 1);
    bst.insert(0, 1);
    bst.insert(4, 1);
    bst.insert(12, 1);

    std::vector<int> order;
    auto sum = 0;
    auto predicate = [&](int& element, int& data) {
        order.push_back(element);
        sum += data;
    };

    bst.preorder(predicate);

    const std::vector<int> expectedOrder = {10, -2, 0, 4, 12};

    REQUIRE(order == expectedOrder);
    REQUIRE(sum == 5);
}

TEST_CASE("BST: Lowest common ancestor", "[bst]") {
    BinarySearchTree<int, int> bst;
    bst.insert(10, 0);
    bst.insert(0, 0);
    bst.insert(-2, 0);
    bst.insert(4, 0);
    bst.insert(12, 0);

    REQUIRE(bst.lowest_common_ancestor(10, 10));
    REQUIRE(bst.lowest_common_ancestor(10, 10)->first == 10);
    REQUIRE(bst.lowest_common_ancestor(10, 0));
    REQUIRE(bst.lowest_common_ancestor(10, 0)->first == 10);
    REQUIRE(bst.lowest_common_ancestor(0, 12));
    REQUIRE(bst.lowest_common_ancestor(0, 12)->first == 10);
    REQUIRE(bst.lowest_common_ancestor(-2, 4));
    REQUIRE(bst.lowest_common_ancestor(-2, 4)->first == 0);
    REQUIRE(bst.lowest_common_ancestor(-5, 4) == nullptr);
}

TEST_CASE("BST: Copy constructor", "[bst]") {
    BinarySearchTree<int, int> bst1;
    bst1.insert(5, 0);
    BinarySearchTree<int, int> bst2 = bst1;

    REQUIRE(bst1.find(5));
    REQUIRE(bst2.find(5));
}

TEST_CASE("BST: Copy assignment", "[bst]") {
    BinarySearchTree<int, int> bst1;
    bst1.insert(5, 0);
    BinarySearchTree<int, int> bst2;
    bst2.insert(10, 0);
    bst2 = bst1;

    REQUIRE(bst1.find(5));
    REQUIRE(bst2.find(5));
}

TEST_CASE("BST: Move constructor", "[bst]") {
    BinarySearchTree<int, int> bst1;
    bst1.insert(5, 0);
    BinarySearchTree<int, int> bst2(std::move(bst1));

    REQUIRE(bst2.find(5));
}

TEST_CASE("BST: Move assignment", "[bst]") {
    BinarySearchTree<int, int> bst1;
    bst1.insert(5, 0);
    BinarySearchTree<int, int> bst2;
    bst2.insert(10, 0);
    bst2 = std::move(bst1);

    REQUIRE(!bst1.find(5));
    REQUIRE(bst2.find(5));
    REQUIRE(!bst2.find(10));
}

TEST_CASE("BST: Other template types", "[bst]") {
    BinarySearchTree<std::string, double> bst;

    REQUIRE(bst.insert("test", 2.3));
    REQUIRE(bst.insert("asdf", 5.4));
    REQUIRE(bst.insert("a", 10.2));

    REQUIRE(bst.find("asdf"));
    REQUIRE(*bst.find("asdf") == Approx(5.4));

    REQUIRE(bst.remove("a"));
}
