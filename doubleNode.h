#ifndef DATA_STRUCTURES_DOUBLENODE_H
#define DATA_STRUCTURES_DOUBLENODE_H
#include <memory>
using namespace std;

namespace doubleNode{
    template <typename T>
    struct Node{
        T data;
        shared_ptr<Node<T>> next;
        weak_ptr<Node<T>> previous;

        Node(T value) : data{value} {}
    };
}

#endif //DATA_STRUCTURES_DOUBLENODE_H
