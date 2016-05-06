#include <iostream>
#ifndef LINKED_LIST
#define LINKED_LIST
#include "int-iterator.h"
class LinkedListIntIterator;

class IntNode {
    friend class LinkedList;
    friend class LinkedListIntIterator;
    private:
        int value;
        IntNode *next;
    public:
        IntNode(int value, IntNode * next) {
            this->value = value;
            this->next = next;
        }
        ~IntNode() {}
};

class LinkedList {
    friend class LinkedListIntIterator;
    private: 
        IntNode * head;
        int length;
    public:
        LinkedList() : head(nullptr), length(0) {}

    bool empty() const {
        return head == nullptr;
    }

    LinkedList &addFront(int value) {
        IntNode *newNode = new IntNode(value, nullptr);
        if (head == nullptr) {
            head = newNode;
        } else {
            IntNode *current = head;
            newNode->next = current;
            head = newNode;
        }
        length++;
        return *this;
    }

    int removeFront() {
        if (head == nullptr) {
            return -1;
        }
        IntNode *old = head;
        head = old->next;
        int value = old->value;
        delete old;
        length--;
        return value;
    }

    int front() const {
        if (head == nullptr) {
            return -1;
        }
        return head->next->value;
    }

    int size() const {
        return length;
    }

    bool contains(int nr) const {
        if (head == nullptr) {
            return false;
        }
        for (IntNode *p = head; p != nullptr; p = p->next) {
            if (p->value == nr) {
                return true;
            }
        }
        return false;
    }

    const LinkedList &print() const {
        if (head == nullptr) {
            std::cout << "[empty]" << std::endl;
        } else {
            std::cout << "[";
            for (IntNode * node = head; node != nullptr; node = node->next) {
                std::cout << ", " << node->value;
            }
            std::cout << "]" << std::endl;
        }
        return *this;
    }

    template<class Func>
    void foreach(Func &f) {
        if (empty()) {
            return;
        }
        for (IntNode* node = head; node != nullptr; node = node->next) {
            f(node->value);
        }
    }

    IntIterator* iterator();

};

class LinkedListIntIterator : public IntIterator {
    private:
        IntNode *current;
    public: 
        LinkedListIntIterator(LinkedList *list);
        int next();
        bool hasNext() const;
};

LinkedListIntIterator::LinkedListIntIterator(LinkedList *list) {
    this->current = list->head;
}

int LinkedListIntIterator::next() {
    int value = current->value;
    current = current->next;
    return value;
}


bool LinkedListIntIterator::hasNext() const {
    return current != nullptr;
}

IntIterator * LinkedList::iterator() {
    return new LinkedListIntIterator(this);
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
