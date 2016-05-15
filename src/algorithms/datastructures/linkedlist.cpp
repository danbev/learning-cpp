#include <iostream>
#ifndef LINKED_LIST
#define LINKED_LIST
#include "node-iterator.h"

class IntNode : public Node<int> {
    friend class LinkedList;
    friend class LinkedListIntIterator;
    public:
        IntNode(int value, Node<int> * next) : Node<int>(value, next) {}
        ~IntNode() {}
};

class LinkedList {
    friend class LinkedListIntIterator;
    private: 
        Node<int>* head;
        int length;
    public:
        LinkedList() : head(nullptr), length(0) {}
        bool empty() const;
        LinkedList &addFront(int value);
        int removeFront();
        int front() const;
        int size() const;
        bool contains(int nr) const;
        const LinkedList &print() const;
        template<class Func>
        void foreach(Func &f) const;
        NodeIterator<int>* iterator();
};

bool LinkedList::empty() const {
    return head == nullptr;
}

LinkedList& LinkedList::addFront(int value) {
    Node<int>* newNode = new IntNode(value, nullptr);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node<int>* current = head;
        newNode->next(current);
        head = newNode;
    }
    length++;
    return *this;
}

int LinkedList::removeFront() {
    if (head == nullptr) {
        return -1;
    }
    Node<int> *old = head;
    head = old->next();
    int value = old->value();
    delete old;
    length--;
    return value;
}

int LinkedList::front() const {
    if (head == nullptr) {
        return -1;
    }
    return head->next()->value();
}

int LinkedList::size() const {
    return length;
}

bool LinkedList::contains(int nr) const {
    if (head == nullptr) {
        return false;
    }
    for (Node<int>* p = head; p != nullptr; p = p->next()) {
        if (p->value() == nr) {
            return true;
        }
    }
    return false;
}

const LinkedList& LinkedList::print() const {
    if (head == nullptr) {
        std::cout << "[empty]" << std::endl;
    } else {
        std::cout << "[";
        for (Node<int>* node = head; node != nullptr; node = node->next()) {
            std::cout << ", " << node->value();
        }
        std::cout << "]" << std::endl;
    }
    return *this;
}

template<class Func>
void LinkedList::foreach(Func &f) const {
    if (empty()) {
        return;
    }
    for (Node<int>* node = head; node != nullptr; node = node->next()) {
        f(node->value());
    }
}

template<>
NodeIterator<int>::NodeIterator(Node<int>* current) {
    this->current_ = current;
}

template<>
int NodeIterator<int>::next() {
    //return current_->next()->value();
    int v = current_->value();
    current_ = current_->next();
    return v;
}

template<>
bool NodeIterator<int>::hasNext() {
    return current_ != nullptr;
}

NodeIterator<int>* LinkedList::iterator() {
    return new NodeIterator<int>(head);
}

/*
 * Reverses the passed in array using the LinkedList
 */ 
void reverseArray(int arr[], int size) {
    LinkedList list;
    for (int i = 0; i < size; i++) {
        list.addFront(arr[i]);
    }
    for (int i = 0; i < size; i++) {
        arr[i] = list.removeFront();
    }
}
#endif
