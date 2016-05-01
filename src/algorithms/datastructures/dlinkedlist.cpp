#include <iostream>
#ifndef DLINKED_LIST
#define DLINKED_LIST
#include "int-iterator.h"

class DIntNode {
    friend class DLinkedList;
    friend class DLinkedListIntIterator;
    private:
        int value;
        DIntNode *next;
        DIntNode *previous;
    public:
        DIntNode(int value, DIntNode *next, DIntNode *previous = nullptr) {
            this->value = value;
            this->next = next;
            this->previous = previous;
        }
        ~DIntNode() {}
};

/*
 * Doubly linked list implementation
 */
class DLinkedList {
    friend class DLinkedListIntIterator;
    private: 
        DIntNode *head;
        DIntNode *tail;
        int length;
    public:
        DLinkedList() : head(nullptr), tail(nullptr), length(0) {}

        bool empty() const {
            return head == nullptr;
        }

        DLinkedList &addFront(int value) {
            DIntNode *newNode = new DIntNode(value, nullptr, nullptr);
            if (empty()) {
                head = newNode;
            } else {
                DIntNode *current = head;
                current->previous = newNode;
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
            DIntNode *old = head;
            head = old->next;
            int value = old->value;
            delete old;
            length--;
            return value;
        }

        int front() const {
            if (empty()) {
                return -1;
            }
            return head->next->value;
        }

        int end() const {
            if (empty()) {
                return -1;
            }
            return (tail == nullptr) ? head->value : tail->value;
        }

        DLinkedList &addEnd(int value) {
            DIntNode *newNode = new DIntNode(value, nullptr, nullptr);
            if (empty()) {
                return addFront(value);
            } 
            DIntNode *current = tail == nullptr ? head:tail;
            current->next = newNode;
            newNode->previous = current;
            tail = newNode;
            length++;
            return *this;
        }

        int removeEnd() {
            if (empty()) {
                return -1;
            }
            if (tail == nullptr) {
                return removeFront();
            }
            DIntNode *old = tail;
            int value = old->value;
            old->previous = nullptr;
            delete old;
            length--;
            return value;
        }

        int size() const {
            return length;
        }

        bool contains(int nr) const {
            if (empty()) {
                return false;
            }
            DIntNode *p = tail == nullptr ? head:tail;
            do {
                if (p->value == nr) {
                    return true;
                }
            } while (p->previous != nullptr);
            return false;
        }

        template<class Func>
        void forEach(Func &f) {
            if (head == nullptr) {
                return;
            }
            DIntNode *p = head;
            do {
                f(p->value);
                p = p->next;
            } while (p != nullptr);
        }

        const DLinkedList &print() const {
            if (head == nullptr) {
                std::cout << "[empty]" << std::endl;
            } else {
                DIntNode * node = head;
                std::cout << "[" << node->value;
                while(node->next) {
                    node = node->next;
                    std::cout << ", " << node->value;
                }
                std::cout << "]" << std::endl;
            }
            return *this;
        }
        IntIterator* iterator();
};

class DLinkedListIntIterator : public IntIterator {
    private:
        DLinkedList * list;
        DIntNode *current;
    public:
        DLinkedListIntIterator(DLinkedList *list);
        int next();
        bool hasNext() const;
};

DLinkedListIntIterator::DLinkedListIntIterator(DLinkedList *list) {
    this->current = list->head;
}

int DLinkedListIntIterator::next() {
    int value = current->value;
    current = current->next;
    return value;
}


bool DLinkedListIntIterator::hasNext() const {
    return current != nullptr;
}

IntIterator * DLinkedList::iterator() {
    return new DLinkedListIntIterator(this);
}
#endif

