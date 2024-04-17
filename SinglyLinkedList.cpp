#include "SinglyLinkedList.h"

template <typename T>
ostream &operator<<(ostream &os, SinglyLinkedList<T> &obj) {
    Node<T> *current = obj.head.get();
    os << "List: " << endl;
    while (current != nullptr){
        os << current->data << " ";
        current = current->next.get();
    }
    os << endl;
    return os;
}

template <typename T>
void SinglyLinkedList<T>::checkIndex(int index) const {
    if(index < 0 || index >= size){
        throw out_of_range("Index out of range");
    }
}

template <typename T>
void SinglyLinkedList<T>::insertAtBeginning(T value) {
    unique_ptr<Node<T>> newNode = make_unique<Node<T>>(value);
    newNode->next = move(head);
    head = move(newNode);
    size++;
}

template <typename T>
void SinglyLinkedList<T>::insertAtEnd(T value) {
    unique_ptr<Node<T>> newNode = make_unique<Node<T>>(value);
    Node<T> *current = head.get();
    if(!current){
        head = move(newNode);
        size++;
        return;
    }
    while (current->next){
        current = current->next.get();
    }
    current->next = move(newNode);
    size++;
}

template <typename T>
void SinglyLinkedList<T>::insertAtIndex(int index, T value) {
    checkIndex(index);

    if (index == 0){
        insertAtBeginning(value);
        return;
    } else if (index == size){
        insertAtEnd(value);
        return;
    } else {
        unique_ptr<Node<T>> newNode = make_unique<Node<T>>(value);
        Node<T> *current = head.get();
        for (int i = 0; i < index - 1; i++) {
            current = current->next.get();
        }
        newNode->next = move(current->next);
        current->next = move(newNode);
        size++;
    }
}

template <typename T>
int SinglyLinkedList<T>::operator[](int index) const {
    checkIndex(index);

    Node<T> *current = head.get();
    for (int i = 0; i < index; i++) {
        current = current->next.get();
    }
    return current->data;
}

template <typename T>
void SinglyLinkedList<T>::removeFromBeginning() {
    if(!head){
        throw out_of_range("List is empty");
    }
    head = move(head->next);
    --size;
}

template <typename T>
void SinglyLinkedList<T>::removeFromEnd() {
    if (!head) {
        throw std::out_of_range("List is empty!");
    }
    if (size == 1) {
        head.reset();
        --size;
        return;
    }
    Node<T> *current = head.get();
    while (current->next->next) {
        current = current->next.get();
    }
    current->next.reset();
    --size;
}

template <typename T>
void SinglyLinkedList<T>::removeAtIndex(int index) {
    checkIndex(index);
    if (index == 0) {
        removeFromBeginning();
        return;
    } else if (index == size - 1) {
        removeFromEnd();
        return;
    }

    Node<T> *current = head.get();
    for (int i = 0; i < index - 1; i++) {
        current = current->next.get();
    }
    current->next = std::move(current->next->next);
    --size;
}

template <typename T>
bool SinglyLinkedList<T>::search(T value) const {
    Node<T> *current = head.get();
    while(current){
        if(current->data == value){
            return true;
        }
        current = current->next.get();
    }
    return false;
}

template <typename T>
int SinglyLinkedList<T>::getSize() const {
    size_t size = 0;

    Node<T> *current = head.get();
    while (current){
        size++;
        current = current->next.get();
    }
    return size;
}

template <typename T>
bool SinglyLinkedList<T>::isEmpty() const {
    return head == nullptr;
}





