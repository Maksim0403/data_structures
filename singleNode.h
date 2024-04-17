#ifndef DATA_STRUCTURES_SINGLENODE_H
#define DATA_STRUCTURES_SINGLENODE_H
#include <memory>
using namespace std;

namespace singleNode{
    template <typename T>
    struct Node{
        T data;
        unique_ptr<Node<T>> next;
        Node(T value) : data{value}, next{nullptr} {};
    };
}

#endif //DATA_STRUCTURES_SINGLENODE_H
