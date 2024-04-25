#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H
#include "DoubleLinkedList.h"

template <typename T>
class Queue{
private:
   DoubleLinkedList<T> list;
public:
    Queue() {}
    Queue(T data) : list{DoubleLinkedList(data)} {}

    void Enqueue(const T value){
        list.insertAtEnd(value);
    }

    T Dequeue(){
        T elem = list[0];
        list.removeFromBeginning();
        return elem;
    }

    T Peek(){
        return list[0];
    }

    bool isEmpty(){
        return list.isEmpty();
    }

    void getSize(){
        list.getSize();
    }
};

#endif //DATA_STRUCTURES_QUEUE_H
