#include <string>
#include <vector>

#include "data_structures/avl.hpp"
#include "third_party/catch.hpp"

using namespace cgn;

TEST_CASE("AVL: Empty", "[avl]") {
    AvlTree<int, int> avl;
}

TEST_CASE("AVL: Insert", "[avl]") {
    AvlTree<int, int> avl;

    REQUIRE(avl.insert(12, 24) == true);
    REQUIRE(avl.insert(10, 0) == true);
    REQUIRE(avl.insert(-8, 0) == true);
    REQUIRE(avl.insert(12, 14) == false);
    REQUIRE(avl.insert(15, 20) == true);
}

TEST_CASE("AVL: Find", "[avl]") {
    AvlTree<int, int> avl;
    avl.insert(10, 20);
    avl.insert(-2, 12);
    avl.insert(0, 4);
    avl.insert(4, 8);
    avl.insert(12, 104);
    avl.insert(20, 43);
    avl.insert(14, 45);

    REQUIRE(avl.find(10));
    REQUIRE(*avl.find(10) == 20);
    REQUIRE(avl.find(-2));
    REQUIRE(*avl.find(-2) == 12);
    REQUIRE(avl.find(0));
    REQUIRE(*avl.find(0) == 4);
    REQUIRE(avl.find(4));
    REQUIRE(*avl.find(4) == 8);
    REQUIRE(avl.find(4));
    REQUIRE(*avl.find(4) == 8);
    REQUIRE(avl.find(12));
    REQUIRE(*avl.find(12) == 104);
    REQUIRE(avl.find(20));
    REQUIRE(*avl.find(20) == 43);
    REQUIRE(avl.find(14));
    REQUIRE(*avl.find(14) == 45);

    REQUIRE(!avl.find(6));
    REQUIRE(!avl.find(30));
    REQUIRE(!avl.find(-20));
}

TEST_CASE("AVL: Remove", "[avl]") {
    AvlTree<int, int> avl;
    avl.insert(10, 8);
    avl.insert(-2, 7);
    avl.insert(0, 5);
    avl.insert(4, 10);
    avl.insert(12, 9);
    avl.insert(20, 12);
    avl.insert(14, 15);

    REQUIRE(avl.remove(4) == true);
    REQUIRE(!avl.find(4));
    REQUIRE(avl.remove(14) == true);
    REQUIRE(avl.remove(-2) == true);
    REQUIRE(avl.remove(-2) == false);
}

TEST_CASE("AVL: Inorder empty", "[avl]") {
    AvlTree<int, int> avl;
    avl.inorder([](auto&, auto&){});
}

TEST_CASE("AVL: Inorder normal", "[avl]") {
    AvlTree<int, int> avl;
    avl.insert(10, 1);
    avl.insert(-2, 1);
    avl.insert(0, 1);
    avl.insert(4, 1);
    avl.insert(12, 1);

    std::vector<int> order;
    auto sum = 0;
    auto predicate = [&](int& element, int& data) {
        order.push_back(element);
        sum += data;
    };

    avl.inorder(predicate);

    const std::vector<int> expectedOrder = {-2, 0, 4, 10, 12};

    REQUIRE(order == expectedOrder);
    REQUIRE(sum == 5);
}

TEST_CASE("AVL: Postorder empty", "[avl]") {
    AvlTree<int, int> avl;
    avl.postorder([](auto&, auto&){});
}

TEST_CASE("AVL: Postorder normal", "[avl]") {
    AvlTree<int, int> avl;
    avl.insert(10, 1);
    avl.insert(-2, 1);
    avl.insert(0, 1);
    avl.insert(4, 1);
    avl.insert(12, 1);

    std::vector<int> order;
    auto sum = 0;
    auto predicate = [&](int& element, int& data) {
        order.push_back(element);
        sum += data;
    };

    avl.postorder(predicate);

    const std::vector<int> expectedOrder = {-2, 4, 12, 10, 0};

    REQUIRE(order == expectedOrder);
    REQUIRE(sum == 5);
}

TEST_CASE("AVL: Preorder empty", "[avl]") {
    AvlTree<int, int> avl;
    avl.preorder([](auto&, auto&){});
}

TEST_CASE("AVL: Preorder normal", "[avl]") {
    AvlTree<int, int> avl;
    avl.insert(10, 1);
    avl.insert(-2, 1);
    avl.insert(0, 1);
    avl.insert(4, 1);
    avl.insert(12, 1);

    std::vector<int> order;
    auto sum = 0;
    auto predicate = [&](int& element, int& data) {
        order.push_back(element);
        sum += data;
    };

    avl.preorder(predicate);

    const std::vector<int> expectedOrder = {0, -2, 10, 4, 12};

    REQUIRE(order == expectedOrder);
    REQUIRE(sum == 5);
}

TEST_CASE("AVL: Lowest common ancestor", "[avl]") {
    AvlTree<int, int> avl;
    avl.insert(10, 0);
    avl.insert(0, 0);
    avl.insert(-2, 0);
    avl.insert(4, 0);
    avl.insert(12, 0);

    REQUIRE(avl.lowest_common_ancestor(10, 10));
    REQUIRE(avl.lowest_common_ancestor(10, 10)->first == 10);
    REQUIRE(avl.lowest_common_ancestor(10, 0));
    REQUIRE(avl.lowest_common_ancestor(10, 0)->first == 0);
    REQUIRE(avl.lowest_common_ancestor(4, 12));
    REQUIRE(avl.lowest_common_ancestor(4, 12)->first == 10);
    REQUIRE(avl.lowest_common_ancestor(-2, 4));
    REQUIRE(avl.lowest_common_ancestor(-2, 4)->first == 0);
    REQUIRE(avl.lowest_common_ancestor(-5, 4) == nullptr);
}

TEST_CASE("AVL: Copy constructor", "[avl]") {
    AvlTree<int, int> avl1;
    avl1.insert(5, 0);
    AvlTree<int, int> avl2 = avl1;

    REQUIRE(avl1.find(5));
    REQUIRE(avl2.find(5));
}

TEST_CASE("AVL: Copy assignment", "[avl]") {
    AvlTree<int, int> avl1;
    avl1.insert(5, 0);
    AvlTree<int, int> avl2;
    avl2.insert(10, 0);
    avl2 = avl1;

    REQUIRE(avl1.find(5));
    REQUIRE(avl2.find(5));
}

TEST_CASE("AVL: Move constructor", "[avl]") {
    AvlTree<int, int> avl1;
    avl1.insert(5, 0);
    AvlTree<int, int> avl2(std::move(avl1));

    REQUIRE(avl2.find(5));
}

TEST_CASE("AVL: Move assignment", "[avl]") {
    AvlTree<int, int> avl1;
    avl1.insert(5, 0);
    AvlTree<int, int> avl2;
    avl2.insert(10, 0);
    avl2 = std::move(avl1);

    REQUIRE(!avl1.find(5));
    REQUIRE(avl2.find(5));
    REQUIRE(!avl2.find(10));
}

TEST_CASE("AVL: Other template types", "[avl]") {
    AvlTree<std::string, double> avl;

    REQUIRE(avl.insert("test", 2.3));
    REQUIRE(avl.insert("asdf", 5.4));
    REQUIRE(avl.insert("a", 10.2));

    REQUIRE(avl.find("asdf"));
    REQUIRE(*avl.find("asdf") == Approx(5.4));

    REQUIRE(avl.remove("a"));
}

TEST_CASE("AVL: Tree height", "[avl]") {
    AvlTree<int, int> avl;
    avl.insert(10, 0);
    avl.insert(-2, 0);
    avl.insert(0, 0);
    avl.insert(4, 0);
    avl.insert(12, 0);

    REQUIRE(avl.height() == 2);

    avl.insert(15, 0);

    REQUIRE(avl.height() == 2);

    avl.insert(-5, 0);

    REQUIRE(avl.height() == 3);
}
