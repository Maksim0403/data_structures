#ifndef DATA_STRUCTURES_SINGLYLINKEDLIST_H
#define DATA_STRUCTURES_SINGLYLINKEDLIST_H
#include <memory>
#include "singleNode.h"
using namespace std;
using namespace singleNode;
template <typename T>

class SinglyLinkedList {
private:
    unique_ptr<Node<T>> head;
    int size;
    void checkIndex(int index) const;
public:
    SinglyLinkedList() : head{nullptr}, size{0} {};
    SinglyLinkedList(T value) : head{make_unique<Node<T>>(value)}, size{1} {};

    void insertAtBeginning(T value);
    void insertAtEnd(T value);
    void insertAtIndex(int index, T value);
    int operator[](int index) const;

    void removeFromBeginning();
    void removeFromEnd();
    void removeAtIndex(int index);

    bool search(T value) const;
    int getSize() const;

    friend ostream &operator<<(ostream &os, SinglyLinkedList &obj);

    bool isEmpty() const;
};


#endif //DATA_STRUCTURES_SINGLYLINKEDLIST_H
