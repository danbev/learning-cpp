#ifndef QUEUE
#define QUEUE
#include "dlinkedlist.cpp"
#include <iostream>

class Queue {
    private:
        DLinkedList * list;
    public:
        Queue();
        Queue &enqueue(int value);
        int dequeue();
        int size() const;
        bool empty() const;
        Iterator<int>* iterator() const;
        void print() const;
};

Queue::Queue() {
    this->list = new DLinkedList();
}

Queue& Queue::enqueue(int value) {
    list->addEnd(value);
    return *this;
}

int Queue::dequeue() {
    return list->removeFront();
}

int Queue::size() const {
    return list->size();
}

bool Queue::empty() const {
    return list->empty();
}

void Queue::print() const {
    list->print();
}

Iterator<int>* Queue::iterator() const {
    return list->iterator();
}
#endif
