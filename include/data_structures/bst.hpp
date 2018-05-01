#ifndef BST_HPP
#define BST_HPP

namespace cgn {
    template <typename T>
    class BinarySearchTree {
    public:
        BinarySearchTree()
            : root(nullptr)
        {}

        bool insert(const T& data);

        virtual ~BinarySearchTree();
    protected:
        class Node {
        public:
            T data;
            Node* left;
            Node* right;

            explicit Node(const T& data)
                : data(data), left(nullptr), right(nullptr)
            {}
        };

    private:
        Node* root;

        virtual bool insert(Node*& node, const T& data);
        virtual void cleanup(Node*& node);
    };

    template <typename T>
    bool BinarySearchTree<T>::insert(const T& data) {
        return insert(root, data);
    }

    template <typename T>
    bool BinarySearchTree<T>::insert(Node*& node, const T& data) {
        if(!node) {
            node = new Node(data);
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
    BinarySearchTree<T>::~BinarySearchTree() {
        cleanup(root);
    }

    template <typename T>
    void BinarySearchTree<T>::cleanup(Node*& node) {
        if(node) {
            cleanup(node->left);
            cleanup(node->right);
            delete node;
            node = nullptr;
        }
    }
}

#endif
