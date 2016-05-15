#ifndef DLINKED_LIST
#define DLINKED_LIST
#include <iostream>
#include "node-iterator.h"
#include "dnode.h"

class DIntNode : public DNode<int> {
    friend class DLinkedList;
    friend class DLinkedListIntIterator;
    friend class NodeIterator<int>;
    public:
        DIntNode(int value, DIntNode* next, DIntNode* previous = nullptr) : DNode<int>(value, next, previous) { }
        ~DIntNode() {}
};

/*
 * Doubly linked list implementation
 */
class DLinkedList {
    friend class DLinkedListIntIterator;
    friend class NodeIterator<int>;
    private: 
        DNode<int>* head;
        DNode<int>* tail;
        int length;
    public:
        DLinkedList() : head(nullptr), tail(nullptr), length(0) {}
        bool empty() const;
        DLinkedList &addFront(int value);
        int removeFront();
        int front() const;
        int end() const;
        DLinkedList &addEnd(int value);
        int removeEnd();
        int size() const;
        bool contains(int nr) const;
        template<class Func>
        void forEach(Func &f);
        const DLinkedList &print() const;
        NodeIterator<int>* iterator();
};

bool DLinkedList::empty() const {
    return head == nullptr;
}

DLinkedList& DLinkedList::addFront(int value) {
    DNode<int> *newNode = new DIntNode(value, nullptr, nullptr);
    if (empty()) {
        head = newNode;
    } else {
        DNode<int> *current = head;
        current->previous(newNode);
        newNode->next(current);
        head = newNode;
    }
    length++;
    return *this;
}

int DLinkedList::removeFront() {
    if (head == nullptr) {
        return -1;
    }
    DNode<int>* old = head;
    head = old->next();
    int value = old->value();
    delete old;
    length--;
    return value;
}

int DLinkedList::front() const {
    if (empty()) {
        return -1;
    }
    return head->next()->value();
}

int DLinkedList::end() const {
    if (empty()) {
        return -1;
    }
    return (tail == nullptr) ? head->value() : tail->value();
}

DLinkedList& DLinkedList::addEnd(int value) {
    DIntNode *newNode = new DIntNode(value, nullptr, nullptr);
    if (empty()) {
        return addFront(value);
    } 
    DNode<int>* current = tail == nullptr ? head:tail;
    current->next(newNode);
    newNode->previous(current);
    tail = newNode;
    length++;
    return *this;
}

int DLinkedList::removeEnd() {
    if (empty()) {
        return -1;
    }
    if (tail == nullptr) {
        return removeFront();
    }
    DNode<int>* old = tail;
    int value = old->value();
    old->previous(nullptr);
    delete old;
    length--;
    return value;
}

int DLinkedList::size() const {
    return length;
}

bool DLinkedList::contains(int nr) const {
    if (empty()) {
        return false;
    }
    DNode<int>* p = tail == nullptr ? head:tail;
    do {
        if (p->value() == nr) {
            return true;
        }
    } while (p->previous() != nullptr);
    return false;
}

template<class Func>
void DLinkedList::forEach(Func &f) {
    if (head == nullptr) {
        return;
    }
    DNode<int>* p = head;
    do {
        f(p->value());
        p = p->next();
    } while (p != nullptr);
}

const DLinkedList& DLinkedList::print() const {
    if (head == nullptr) {
        std::cout << "[empty]" << std::endl;
    } else {
        DNode<int>* node = head;
        std::cout << "[" << node->value();
        while(node->next()) {
            node = node->next();
            std::cout << ", " << node->value();
        }
        std::cout << "]" << std::endl;
    }
    return *this;
}

NodeIterator<int>* DLinkedList::iterator() {
    return new NodeIterator<int>(head);
}
#endif
