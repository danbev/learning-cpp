#ifndef STACK
#define STACK
#include <iostream>
#include "linkedlist.cpp"

class Stack {
    private:
        LinkedList * list;
    public:
        Stack();
        Stack &push(int value);
        int pop();
        int size() const;
        Iterator<int>* iterator() const;
        void print() const;
};

Stack::Stack() {
    this->list = new LinkedList();
}

Stack& Stack::push(int value) {
    list->addFront(value);
    return *this;
}

int Stack::pop() {
    return list->removeFront();
}

int Stack::size() const {
    return list->size();
}

void Stack::print() const {
    list->print();
}

Iterator<int>* Stack::iterator() const {
    return list->iterator();
}
#endif
