#ifndef QUEUE_FACTORY_HPP
#define QUEUE_FACTORY_HPP

#include "Queue.hpp"
#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"

class QueueFactory {
public:
    // No length parameter -> returns a LinkedQueue (unbounded)
    static Queue<int>* GetQueue() {
        return new LinkedQueue<int>();
    }

    // Length parameter provided -> returns an ArrayQueue (bounded)
    static Queue<int>* GetQueue(int maxSize) {
        return new ArrayQueue<int>(maxSize);
    }
};

#endif
