#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
public:
    LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList(LinkedList&& other) noexcept;
    ~LinkedList();

    LinkedList& operator=(const LinkedList& other);
    LinkedList& operator=(LinkedList&& other) noexcept;

    void add(const T& value);
    void print() const;

private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;
    void clear();
    void copyFrom(const LinkedList& other);
};

#include "LinkedList.cpp"

#endif // LINKEDLIST_H
