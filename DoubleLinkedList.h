#ifndef DATA_STRUCTURES_DOUBLELINKEDLIST_H
#define DATA_STRUCTURES_DOUBLELINKEDLIST_H
#include <memory>
#include "doubleNode.h"
using namespace std;
using namespace doubleNode;
template <typename T>

class DoubleLinkedList {
private:
    shared_ptr<doubleNode::Node<T>> head;
    shared_ptr<doubleNode::Node<T>> tail;
    int size;
    void checkIndex(int index) const;
public:
    DoubleLinkedList() : head{nullptr}, tail{nullptr}, size{0} {}
    DoubleLinkedList(T value) : head{make_shared<doubleNode::Node<T>>(value)}, tail{head}, size{1} {}

    void insertAtBeginning(T value);
    void insertAtEnd(T value);
    void insertAtIndex(int index, T value);
    int operator[](int index) const;

    void removeFromBeginning();
    void removeFromEnd();
    void removeAtIndex(int index);

    bool isEmpty() const;
    bool search(T value) const;
    int getSize() const;

    friend ostream &operator<<(ostream &os, DoubleLinkedList &obj);
};




#endif //DATA_STRUCTURES_DOUBLELINKEDLIST_H
