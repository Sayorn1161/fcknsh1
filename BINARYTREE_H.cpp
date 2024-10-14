#ifndef BINARYTREE_H
#define BINARYTREE_H

template <typename T>
class BinaryTree {
public:
    BinaryTree();
    BinaryTree(const BinaryTree& other);
    BinaryTree(BinaryTree&& other) noexcept;
    ~BinaryTree();

    BinaryTree& operator=(const BinaryTree& other);
    BinaryTree& operator=(BinaryTree&& other) noexcept;

    void add(const T& value);
    void print() const;

private:
    struct Node {
        T data;
        Node* left;
        Node* right;
    };

    Node* root;
    void clear();
    void copyFrom(const BinaryTree& other);
    void addHelper(Node*& node, const T& value);
    void printHelper(Node* node) const;
};

#include "BinaryTree.cpp"

#endif // BINARYTREE_H
