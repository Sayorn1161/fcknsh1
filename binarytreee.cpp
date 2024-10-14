#include "BinaryTree.h"
#include <iostream>

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& other) : root(nullptr) {
    copyFrom(other);
}

template <typename T>
BinaryTree<T>::BinaryTree(BinaryTree&& other) noexcept : root(other.root) {
    other.root = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    clear();
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree&& other) noexcept {
    if (this != &other) {
        clear();
        root = other.root;
        other.root = nullptr;
    }
    return *this;
}

template <typename T>
void BinaryTree<T>::add(const T& value) {
    addHelper(root, value);
}

template <typename T>
void BinaryTree<T>::print() const {
    printHelper(root);
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::clear() {
    while (root) {
        Node* temp = root;
        root = root->next;
        delete temp;
    }
}

template <typename T>
void BinaryTree<T>::copyFrom(const BinaryTree& other) {
    // Операція копіювання
}

template <typename T>
void BinaryTree<T>::addHelper(Node*& node, const T& value) {
    if (!node) {
        node = new Node{value, nullptr, nullptr};
    } else if (value < node->data) {
        addHelper(node->left, value);
    } else {
        addHelper(node->right, value);
    }
}

template <typename T>
void BinaryTree<T>::printHelper(Node* node) const {
    if (node) {
        printHelper(node->left);
        std::cout << node->data << " ";
        printHelper(node->right);
    }
}
