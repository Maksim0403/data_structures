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
    void checkIndex(int index) const{
        if(index < 0 || index >= size){
            throw out_of_range("Index out of range");
        }
    };
public:
    DoubleLinkedList() : head{nullptr}, tail{nullptr}, size{0} {}
    DoubleLinkedList(T value) : head{make_shared<doubleNode::Node<T>>(value)}, tail{head}, size{1} {}

    void insertAtBeginning(T value){
        shared_ptr<doubleNode::Node<T>> newNode = make_shared<doubleNode::Node<T>>(value);
        if(!head){
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        size++;
    };
    void insertAtEnd(T value){
        shared_ptr<doubleNode::Node<T>> newNode = make_shared<doubleNode::Node<T>>(value);
        if(!head){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        size++;
    };
    void insertAtIndex(int index, T value){
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
    };
    int operator[](int index) const{
        checkIndex(index);
        shared_ptr<doubleNode::Node<T>> current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        return current->data;
    };

    void removeFromBeginning(){
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
    };
    void removeFromEnd(){
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
    };
    void removeAtIndex(int index){
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
    };

    bool isEmpty() const{
        return head == nullptr;
    };
    bool search(T value) const{
        shared_ptr<doubleNode::Node<T>> current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    };
    int getSize() const{
        return size;
    };

    friend ostream &operator<<(ostream &os, DoubleLinkedList &obj){
        os << "List data: " << endl;
        shared_ptr<doubleNode::Node<T>> current = obj.head;
        while (current) {
            os << current->data << " ";
            current = current->next;
        }
        os << endl;
        return os;
    };
};




#endif //DATA_STRUCTURES_DOUBLELINKEDLIST_H
