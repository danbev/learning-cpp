#include <iostream>
#include "linkedlist.cpp"
#ifndef STACK
#define STACK

class Stack {
    private:
        LinkedList * list;
    public:
        Stack();
        Stack &push(int value);
        int pop();
        int size() const;
        IntIterator* iterator() const;
        void print() const;
};

class StackIterator : public IntIterator {
    private:
        const Stack * stack;
    public:
        StackIterator(const Stack *stack);
        int next() const;
        bool hasNext() const;
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

IntIterator * Stack::iterator() const {
    return list->iterator();
}
#endif
