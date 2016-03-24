#include <iostream>
#include "iterator.cpp"
class IntIterator;

class IntNode {
    friend class LinkedList;
    friend class IntIterator;
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
    friend class IntIterator;
    private: 
        IntNode * head;
        int length;
    public:
        LinkedList() : head(NULL), length(0) {}

    bool empty() const {
        return head == NULL;
    }

    LinkedList &addFront(int value) {
        IntNode *newNode = new IntNode(value, NULL);
        if (head == NULL) {
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
        if (head == NULL) {
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
        if (head == NULL) {
            return -1;
        }
        return head->next->value;
    }

    int size() const {
        return length;
    }

    bool contains(int nr) const {
        if (head == NULL) {
            return false;
        }
        IntNode *p = head;
        do {
            if (p->value == nr) {
                return true;
            }
        } while (p->next != NULL);
        return false;
    }

    const LinkedList &print() const {
        if (head == NULL) {
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

    template<class Func>
    void foreach(Func &f) {
        if (empty()) {
            return;
        }
        IntNode * node = head;
        while(node->next) {
            node = node->next;
            f(node->value);
        }
    }

    IntIterator iterator();

};

class IntIterator : public Iterator<int> {
    private:
        LinkedList * list;
    public: 
        IntIterator(LinkedList *list) {
            this->list = list;
        }
        int next() {
            int value = list->head->value;
            list->head = list->head->next;
            return value;
        }
        bool hasNext() {
            return list->head != NULL;
        }
};


IntIterator LinkedList::iterator() {
    return IntIterator(this);
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

