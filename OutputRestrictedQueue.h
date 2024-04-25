#ifndef DATA_STRUCTURES_OUTPUTRESTRICTEDQUEUE_H
#define DATA_STRUCTURES_OUTPUTRESTRICTEDQUEUE_H
#include "Queue.h"

template <typename T>
class OutputRestrictedQueue : public Queue<T>{
public:
    OutputRestrictedQueue() {}
    OutputRestrictedQueue(T data) : Queue<T>(data) {}

    void popFront(){
        this->list.removeFromBeginning();
    }
};

#endif //DATA_STRUCTURES_OUTPUTRESTRICTEDQUEUE_H
