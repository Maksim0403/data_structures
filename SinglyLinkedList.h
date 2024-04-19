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
    void checkIndex(int index) const{
        if(index < 0 || index >= size){
            throw out_of_range("Index out of range");
        }
    };
public:
    SinglyLinkedList() : head{nullptr}, size{0} {};
    SinglyLinkedList(T value) : head{make_unique<Node<T>>(value)}, size{1} {};

    void insertAtBeginning(T value){
        unique_ptr<Node<T>> newNode = make_unique<Node<T>>(value);
        newNode->next = move(head);
        head = move(newNode);
        size++;
    };
    void insertAtEnd(T value){
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
    };
    void insertAtIndex(int index, T value){
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
    };
    int operator[](int index) const{
        checkIndex(index);

        Node<T> *current = head.get();
        for (int i = 0; i < index; i++) {
            current = current->next.get();
        }
        return current->data;
    };

    void removeFromBeginning(){
        if(!head){
            throw out_of_range("List is empty");
        }
        head = move(head->next);
        --size;
    };
    void removeFromEnd(){
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
    };
    void removeAtIndex(int index){
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
    };

    bool search(T value) const{
        Node<T> *current = head.get();
        while(current){
            if(current->data == value){
                return true;
            }
            current = current->next.get();
        }
        return false;
    };
    int getSize() const{
        size_t size = 0;

        Node<T> *current = head.get();
        while (current){
            size++;
            current = current->next.get();
        }
        return size;
    };

    friend ostream &operator<<(ostream &os, SinglyLinkedList<T> &obj){
        Node<T> *current = obj.head.get();
        os << "List: " << endl;
        while (current != nullptr){
            os << current->data << " ";
            current = current->next.get();
        }
        os << endl;
        return os;
    };

    bool isEmpty() const{
        return head == nullptr;
    };
};


#endif //DATA_STRUCTURES_SINGLYLINKEDLIST_H
