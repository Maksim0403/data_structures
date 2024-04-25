#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H
#include <stdexcept>

#define MAX 30

template <typename T>
class Stack{
private:
    T array[MAX];
    int size;
public:
    Stack() : size{0} {}
    Stack(T data) : size{1} {array[0] = data;}

    void Push(const T value){
        if(isFull()){
            throw std::out_of_range("Stack is full!");
        }
        array[size] = value;
        size++;
    }

    T Pop(){
        if(isEmpty()){
            throw std::out_of_range("Stack is empty!");
        }

        size--;
        return array[size];
    }

    T Peek(){
        return array[size - 1];
    }

    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == MAX;
    }

};

#endif //DATA_STRUCTURES_STACK_H
