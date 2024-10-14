#include "LinkedList.h"
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other) : head(nullptr) {
    copyFrom(other);
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList&& other) noexcept : head(other.head) {
    other.head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList&& other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        other.head = nullptr;
    }
    return *this;
}

template <typename T>
void LinkedList<T>::add(const T& value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

template <typename T>
void LinkedList<T>::print() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void LinkedList<T>::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::copyFrom(const LinkedList& other) {
    if (other.head) {
        head = new Node{other.head->data, nullptr};
        Node* current = head;
        Node* otherCurrent = other.head->next;

        while (otherCurrent) {
            current->next = new Node{otherCurrent->data, nullptr};
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }
}
