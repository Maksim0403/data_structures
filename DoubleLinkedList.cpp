#include "DoubleLinkedList.h"
template <typename T>
ostream &operator<<(ostream &os, DoubleLinkedList<T> &obj) {
    os << "List data: " << endl;
    shared_ptr<doubleNode::Node<T>> current = obj.head;
    while (current) {
        os << current->data << " ";
        current = current->next;
    }
    os << endl;
    return os;
}

template <typename T>
void DoubleLinkedList<T>::checkIndex(int index) const {
    if(index < 0 || index >= size){
        throw out_of_range("Index out of range");
    }
}

template <typename T>
void DoubleLinkedList<T>::insertAtBeginning(T value) {
    shared_ptr<doubleNode::Node<T>> newNode = make_shared<doubleNode::Node<T>>(value);
    if(!head){
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    size++;
}

template <typename T>
void DoubleLinkedList<T>::insertAtEnd(T value) {
    shared_ptr<doubleNode::Node<T>> newNode = make_shared<doubleNode::Node<T>>(value);
    if(!head){
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    size++;
}

template <typename T>
void DoubleLinkedList<T>::insertAtIndex(int index, T value) {
    checkIndex(index);

    if(index == 0){
        insertAtBeginning(value);
        return;
    } else if (index == size){
        insertAtEnd(value);
        return;
    } else {
        shared_ptr<doubleNode::Node<T>> newNode = make_shared<doubleNode::Node<T>>(value);
        shared_ptr<doubleNode::Node<T>> current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->previous = current;
        current->next->previous = newNode;
        current->next = newNode;
        size++;
    }
}

template <typename T>
int DoubleLinkedList<T>::operator[](int index) const {
    checkIndex(index);
    shared_ptr<doubleNode::Node<T>> current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
void DoubleLinkedList<T>::removeFromBeginning() {
    if(!head){
        return;
    }
    if(head == tail){
        head = tail = nullptr;
    } else {
        head = head->next;
        head->previous.reset();
    }
    --size;
}

template<typename T>
void DoubleLinkedList<T>::removeFromEnd() {
    if (!tail) {
        return;
    }
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->previous.lock();
        tail->next = nullptr;
    }
    --size;
}

template<typename T>
void DoubleLinkedList<T>::removeAtIndex(int index) {
    checkIndex(index);
    if (index == 0) {
        head = head->next;
        if (head) {
            head->previous.reset();
        } else {
            tail.reset();
        }
    } else if (index == size - 1) {
        tail = tail->previous.lock();
        tail->next.reset();
    } else {
        shared_ptr<doubleNode::Node<T>> current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->previous.lock()->next = current->next;
        current->next->previous = current->previous;
    }
    --size;
}

template<typename T>
int DoubleLinkedList<T>::getSize() const {
    return size;
}


template<typename T>
bool DoubleLinkedList<T>::search(T value) const {
    shared_ptr<doubleNode::Node<T>> current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}


template<typename T>
bool DoubleLinkedList<T>::isEmpty() const {
    return head == nullptr;
}



