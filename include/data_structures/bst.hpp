#ifndef BST_HPP
#define BST_HPP

#include <functional>
#include <memory>

namespace cgn {
    template <typename T>
    class BinarySearchTree {
    public:
        BinarySearchTree()
            : root(nullptr)
        {}

        virtual bool insert(const T& data);
        virtual bool find(const T& data) const;
        virtual bool remove(const T& data);
        void inorder(std::function<void(T&)> predicate);
        void postorder(std::function<void(T&)> predicate);
        void preorder(std::function<void(T&)> predicate);
        std::unique_ptr<T> lowest_common_ancestor(const T& a, const T& b) const;

    protected:
        struct Node {
            T data;
            std::shared_ptr<Node> left;
            std::shared_ptr<Node> right;

            explicit Node(const T& data)
                : data(data), left(nullptr), right(nullptr)
            {}
        };

    private:
        std::shared_ptr<Node> root;

        virtual bool insert(std::shared_ptr<Node>& node, const T& data);
        virtual bool find(std::shared_ptr<Node> node, const T& data) const;
        virtual bool remove(std::shared_ptr<Node>& node, const T& data);
        void inorder(std::shared_ptr<Node> node, std::function<void(T&)> predicate);
        void postorder(std::shared_ptr<Node> node, std::function<void(T&)> predicate);
        void preorder(std::shared_ptr<Node> node, std::function<void(T&)> predicate);
    };

    template <typename T>
    bool BinarySearchTree<T>::insert(const T& data) {
        return insert(root, data);
    }

    template <typename T>
    bool BinarySearchTree<T>::find(const T& data) const {
        return find(root, data);
    }

    template <typename T>
    bool BinarySearchTree<T>::remove(const T& data) {
        return remove(root, data);
    }

    template <typename T>
    void BinarySearchTree<T>::inorder(std::function<void(T&)> predicate) {
        inorder(root, predicate);
    }

    template <typename T>
    void BinarySearchTree<T>::postorder(std::function<void(T&)> predicate) {
        postorder(root, predicate);
    }

    template <typename T>
    void BinarySearchTree<T>::preorder(std::function<void(T&)> predicate) {
        preorder(root, predicate);
    }

    template <typename T>
    std::unique_ptr<T> BinarySearchTree<T>::lowest_common_ancestor(const T& a, const T& b) const {
        if(!find(a) || !find(b))
            return nullptr;

        auto current = root;
        while(current) {
            if(current->data > a && current->data > b)
                current = current->left;
            else if(current->data < a && current->data < b)
                current = current->right;
            else
                break;
        }

        return std::make_unique<T>(current->data);
    }

    template <typename T>
    bool BinarySearchTree<T>::insert(std::shared_ptr<Node>& node, const T& data) {
        if(!node) {
            node = std::make_shared<Node>(data);
            return true;
        }

        if(data < node->data) {
            return insert(node->left, data);
        } else if(data > node->data) {
            return insert(node->right, data);
        }

        return false;
    }

    template <typename T>
    bool BinarySearchTree<T>::find(std::shared_ptr<Node> node, const T& data) const {
        if(!node) {
            return false;
        }

        if(data < node->data) {
            return find(node->left, data);
        } else if(data > node->data) {
            return find(node->right, data);
        }

        return true;
    }

    template <typename T>
    bool BinarySearchTree<T>::remove(std::shared_ptr<Node>& node, const T& data) {
        if(!node) {
            return false;
        }

        if(data < node->data) {
            return remove(node->left, data);
        } else if(data > node->data) {
            return remove(node->right, data);
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
        node->data = nextNode->data;
        // Delete successor
        return remove(node->right, node->data);
    }

    template <typename T>
    void BinarySearchTree<T>::inorder(std::shared_ptr<Node> node, std::function<void(T&)> predicate) {
        if(!node)
            return;

        inorder(node->left, predicate);
        predicate(node->data);
        inorder(node->right, predicate);
    }

    template <typename T>
    void BinarySearchTree<T>::postorder(std::shared_ptr<Node> node, std::function<void(T&)> predicate) {
        if(!node)
            return;

        postorder(node->left, predicate);
        postorder(node->right, predicate);
        predicate(node->data);
    }

    template <typename T>
    void BinarySearchTree<T>::preorder(std::shared_ptr<Node> node, std::function<void(T&)> predicate) {
        if(!node)
            return;

        predicate(node->data);
        preorder(node->left, predicate);
        preorder(node->right, predicate);
    }
}

#endif
