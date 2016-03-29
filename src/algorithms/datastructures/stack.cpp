#include <iostream>

class IntNode {
    friend class LinkedIntList;
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

class LinkedIntList {
    private: 
        IntNode * head;
        int length;
    public:
        LinkedIntList() : head(nullptr), length(0) {}
        LinkedIntList &push(int value) {
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
        int pop() {
            if (head == nullptr) {
                return 0;
            }
            IntNode *old = head;
            head = old->next;
            int value = old->value;
            delete old;
            length--;
            return value;
        }
        int size() {
            return length;
        }
        LinkedIntList &print() {
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

/*
 * Reverses the passed in array using the LinkedIntList
 */ 
void reverseArray(int arr[], int size) {
    LinkedIntList list;
    for (int i = 0; i < size; i++) {
        list.push(arr[i]);
    }
    for (int i = 0; i < size; i++) {
        arr[i] = list.pop();
    }
}

