#include <iostream>

class IntNode {
    friend class DLinkedList;
    private:
        int value;
        IntNode *next;
        IntNode *previous;
    public:
        IntNode(int value, IntNode *next, IntNode *previous = nullptr) {
            this->value = value;
            this->next = next;
            this->previous = previous;
        }
        ~IntNode() {}
};

/*
 * Doubly linked list implementation
 */
class DLinkedList {
    private: 
        IntNode *head;
        IntNode *tail;
        int length;
    public:
        DLinkedList() : head(nullptr), tail(nullptr), length(0) {}

        bool empty() const {
            return head == nullptr;
        }

        DLinkedList &addFront(int value) {
            IntNode *newNode = new IntNode(value, nullptr, nullptr);
            if (empty()) {
                head = newNode;
            } else {
                IntNode *current = head;
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
            IntNode *old = head;
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
            IntNode *newNode = new IntNode(value, nullptr, nullptr);
            if (empty()) {
                return addFront(value);
            } 
            IntNode *current = tail == nullptr ? head:tail;
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
            IntNode *old = tail;
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
            IntNode *p = tail == nullptr ? head:tail;
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
            IntNode *p = head;
            do {
                f(p->value);
                p = p->next;
            } while (p != nullptr);
        }

        const DLinkedList &print() const {
            if (head == nullptr) {
                std::cout << "[empty]" << std::endl;
            } else {
                IntNode * node = head;
                std::cout << "[" << node->value;
                while(node->next) {
                    node = node->next;
                    std::cout << ", " << node->value;
                }
                std::cout << "]" << std::endl;
            }
            return *this;
        }
};

