#ifndef BST_HPP
#define BST_HPP

#include <functional>
#include <memory>

namespace cgn {
    template <typename K, typename V>
    class BinarySearchTree {
    public:
        BinarySearchTree()
            : root(nullptr)
        {}

        virtual bool insert(const K& key, const V& data);
        virtual std::unique_ptr<V> find(const K& key) const;
        virtual bool remove(const K& key);
        void inorder(std::function<void(K&, V&)> predicate);
        void postorder(std::function<void(K&, V&)> predicate);
        void preorder(std::function<void(K&, V&)> predicate);
        std::unique_ptr<std::pair<K, V>> lowest_common_ancestor(const K& a, const K& b) const;

    protected:
        struct Node {
            K key;
            V data;
            std::shared_ptr<Node> left;
            std::shared_ptr<Node> right;

            explicit Node(const K& key, const V& data)
                : key(key), data(data), left(nullptr), right(nullptr)
            {}
        };

    private:
        std::shared_ptr<Node> root;

        virtual bool insert(std::shared_ptr<Node>& node, const K& key, const V& data);
        virtual std::unique_ptr<V> find(std::shared_ptr<Node> node, const K& key) const;
        virtual bool remove(std::shared_ptr<Node>& node, const K& key);
        void inorder(std::shared_ptr<Node> node, std::function<void(K&, V&)> predicate);
        void postorder(std::shared_ptr<Node> node, std::function<void(K&, V&)> predicate);
        void preorder(std::shared_ptr<Node> node, std::function<void(K&, V&)> predicate);
    };

    template <typename K, typename V>
    bool BinarySearchTree<K, V>::insert(const K& key, const V& data) {
        return insert(root, key, data);
    }

    template <typename K, typename V>
    std::unique_ptr<V> BinarySearchTree<K, V>::find(const K& key) const {
        return find(root, key);
    }

    template <typename K, typename V>
    bool BinarySearchTree<K, V>::remove(const K& key) {
        return remove(root, key);
    }

    template <typename K, typename V>
    void BinarySearchTree<K, V>::inorder(std::function<void(K&, V&)> predicate) {
        inorder(root, predicate);
    }

    template <typename K, typename V>
    void BinarySearchTree<K, V>::postorder(std::function<void(K&, V&)> predicate) {
        postorder(root, predicate);
    }

    template <typename K, typename V>
    void BinarySearchTree<K, V>::preorder(std::function<void(K&, V&)> predicate) {
        preorder(root, predicate);
    }

    template <typename K, typename V>
    std::unique_ptr<std::pair<K, V>> BinarySearchTree<K, V>::lowest_common_ancestor(const K& a, const K& b) const {
        if(!find(a) || !find(b))
            return nullptr;

        auto current = root;
        while(current) {
            if(current->key > a && current->key > b)
                current = current->left;
            else if(current->key < a && current->key < b)
                current = current->right;
            else
                break;
        }

        auto pair = std::make_pair(current->key, current->data);
        return std::make_unique<std::pair<K, V>>(pair);
    }

    template <typename K, typename V>
    bool BinarySearchTree<K, V>::insert(std::shared_ptr<Node>& node, const K& key, const V& data) {
        if(!node) {
            node = std::make_shared<Node>(key, data);
            return true;
        }

        if(key < node->key) {
            return insert(node->left, key, data);
        } else if(key > node->key) {
            return insert(node->right, key, data);
        }

        return false;
    }

    template <typename K, typename V>
    std::unique_ptr<V> BinarySearchTree<K, V>::find(std::shared_ptr<Node> node, const K& key) const {
        if(!node) {
            return nullptr;
        }

        if(key < node->key) {
            return find(node->left, key);
        } else if(key > node->key) {
            return find(node->right, key);
        }

        return std::make_unique<V>(node->data);
    }

    template <typename K, typename V>
    bool BinarySearchTree<K, V>::remove(std::shared_ptr<Node>& node, const K& key) {
        if(!node) {
            return false;
        }

        if(key < node->key) {
            return remove(node->left, key);
        } else if(key > node->key) {
            return remove(node->right, key);
        }

        if(!node->left) {
            node = node->right;
            return true;
        }

        if(!node->right) {
            node = node->left;
            return true;
        }

        // Find successor node
        auto nextNode = node->right;
        while(nextNode->left)
            nextNode = node->left;

        // Set current node to successor
        node->key = nextNode->key;
        node->data = nextNode->data;
        // Delete successor
        return remove(node->right, node->key);
    }

    template <typename K, typename V>
    void BinarySearchTree<K, V>::inorder(std::shared_ptr<Node> node, std::function<void(K&, V&)> predicate) {
        if(!node)
            return;

        inorder(node->left, predicate);
        predicate(node->key, node->data);
        inorder(node->right, predicate);
    }

    template <typename K, typename V>
    void BinarySearchTree<K, V>::postorder(std::shared_ptr<Node> node, std::function<void(K&, V&)> predicate) {
        if(!node)
            return;

        postorder(node->left, predicate);
        postorder(node->right, predicate);
        predicate(node->key, node->data);
    }

    template <typename K, typename V>
    void BinarySearchTree<K, V>::preorder(std::shared_ptr<Node> node, std::function<void(K&, V&)> predicate) {
        if(!node)
            return;

        predicate(node->key, node->data);
        preorder(node->left, predicate);
        preorder(node->right, predicate);
    }
}

#endif
