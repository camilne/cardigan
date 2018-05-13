#ifndef AVL_HPP
#define AVL_HPP

#include <cassert>
#include <cmath>
#include "data_structures/bst.hpp"

namespace cgn {
    template <typename K, typename V>
    struct AvlNode {
        K key;
        V data;
        std::shared_ptr<AvlNode> left;
        std::shared_ptr<AvlNode> right;
        int height;

        AvlNode(const K& key, const V& data)
            : key(key), data(data), left(nullptr), right(nullptr), height(0)
        {}
    };

    template <typename K, typename V>
    class AvlTree : public BinarySearchTree<K, V, AvlNode<K, V>> {
        using Node = AvlNode<K, V>;
    public:
        virtual bool insert(const K& key, const V& data) override;
        int height() const;
        virtual bool remove(const K& key) override;

    protected:
        virtual bool insert(std::shared_ptr<Node>& node, const K& key, const V& data) override;
        virtual bool remove(std::shared_ptr<Node>& node, const K& key) override;

    private:
        const static int ALLOWED_IMBALANCE;

        void balance(std::shared_ptr<Node>& node);
        int height(std::shared_ptr<Node> node) const;
        void rotateRight(std::shared_ptr<Node>& node);
        void rotateLeft(std::shared_ptr<Node>& node);
    };

    template <typename K, typename V>
    const int AvlTree<K, V>::ALLOWED_IMBALANCE = 1;

    /*
    AVL insert
    -------------------
    Inserts a new node into the AVL if the key does not yet exist and rebalances
    if successful.

    Time complexity
    ---------------
    O(log n), where n is the number of nodes in the tree.

    Space complexity
    ----------------
    O(log n), where n is the number of nodes in the tree.
    */
    template <typename K, typename V>
    bool AvlTree<K, V>::insert(const K& key, const V& data) {
        return BinarySearchTree<K, V, AvlNode<K, V>>::insert(key, data);
    }

    /*
    AVL height
    -------------------
    Return the height of the AVL tree. If a node is nullptr, then its height is
    -1. The height of a node is the maximum of the height of its children plus
    1. Return the height of the root node.

    Time complexity
    ---------------
    O(1), since the height is cached in the node and updated on balancing.

    Space complexity
    ----------------
    O(1)
    */
    template <typename K, typename V>
    int AvlTree<K, V>::height() const {
        return height(BinarySearchTree<K, V, AvlNode<K, V>>::root);
    }

    /*
    AVL remove/delete
    -------------------
    Remove a node from the AVL if it exists. Return true and rebalance if
    successful. Return false otherwise.

    Time complexity
    ---------------
    O(log n), where n is the number of nodes in the tree.

    Space complexity
    ----------------
    O(log n), where n is the number of nodes in the tree.
    */
    template <typename K, typename V>
    bool AvlTree<K, V>::remove(const K& key) {
        return BinarySearchTree<K, V, AvlNode<K, V>>::remove(key);
    }

    // ========== Recursive helper functions ==============

    template <typename K, typename V>
    bool AvlTree<K, V>::insert(std::shared_ptr<Node>& node, const K& key, const V& data) {
        auto result = BinarySearchTree<K, V, AvlNode<K, V>>::insert(node, key, data);
        if(result) {
            balance(node);
        }
        return result;
    }

    template <typename K, typename V>
    bool AvlTree<K, V>::remove(std::shared_ptr<Node>& node, const K& key) {
        auto result = BinarySearchTree<K, V, AvlNode<K, V>>::remove(node, key);
        if(result) {
            balance(node);
        }
        return result;
    }

    // ========== End recursive helper functions ==============

    /*
    AVL balance
    -------------------
    Rebalances the AVL tree at the given node so that the height of the left and
    right subtrees differ by no more than ALLOWED_IMBALANCE

    Time complexity
    ---------------
    O(1)

    Space complexity
    ----------------
    O(1)
    */
    template <typename K, typename V>
    void AvlTree<K, V>::balance(std::shared_ptr<Node>& node) {
        if(!node)
            return;

        if(height(node->left) - height(node->right) > ALLOWED_IMBALANCE) {
            if(height(node->left->left) >= height(node->left->right)) {
                rotateRight(node);
            } else {
                rotateLeft(node->left);
                rotateRight(node);
            }
        } else if(height(node->right) - height(node->left) > ALLOWED_IMBALANCE) {
            if(height(node->right->right) >= height(node->right->left)) {
                rotateLeft(node);
            } else {
                rotateRight(node->right);
                rotateLeft(node);
            }
        }

        node->height = std::max(height(node->left), height(node->right)) + 1;
    }

    /*
    AVL height
    -------------------
    Return the height of the AVL node. If a node is nullptr, then its height is
    -1. The height of a node is the maximum of the height of its children plus
    1.

    Time complexity
    ---------------
    O(1)

    Space complexity
    ----------------
    O(1)
    */
    template <typename K, typename V>
    int AvlTree<K, V>::height(std::shared_ptr<Node> node) const {
        return node ? node->height : -1;
    }

    /*
    AVL rotate right
    -------------------
    Rotates a node right. The left child becomes the root and the node becomes
    the right child of the root.

    Time complexity
    ---------------
    O(1)

    Space complexity
    ----------------
    O(1)
    */
    template <typename K, typename V>
    void AvlTree<K, V>::rotateRight(std::shared_ptr<Node>& node) {
        assert(node);
        auto child = node->left;
        assert(child);

        node->left = child->right;
        child->right = node;
        node->height = std::max(height(node->left), height(node->right)) + 1;
        child->right->height = std::max(height(child->right->left), height(child->right->right)) + 1;
        node = child;
    }

    /*
    AVL rotate left
    -------------------
    Rotates a node left. The right child becomes the root and the node becomes
    the left child of the root.

    Time complexity
    ---------------
    O(1)

    Space complexity
    ----------------
    O(1)
    */
    template <typename K, typename V>
    void AvlTree<K, V>::rotateLeft(std::shared_ptr<Node>& node) {
        assert(node);
        auto child = node->right;
        assert(child);

        node->right = child->left;
        child->left = node;
        node->height = std::max(height(node->left), height(node->right)) + 1;
        child->left->height = std::max(height(child->left->left), height(child->left->right)) + 1;
        node = child;
    }
}

#endif
