#include <stdio.h>
#include <string.h>

class Node {
    friend class SequentialSymbolTable;
    private: 
        int key;
        char value;
        Node *next;
    public:
        Node(int key, int value, Node *next = NULL) {
            this->key = key;
            this->value = value;
            this->next = next;
        };
        ~Node() {};
};

/*
 * Sequential symbol table that uses a linked list.
 */
class SequentialSymbolTable {
    private:
        Node *head;
        void throwNoSuchKey(int key) {
            throw "No such key: " + std::to_string(key);
        }
    public:
        SequentialSymbolTable() :head(NULL) {};
        void put(int key, char value) {
            for (Node *n = head; n != NULL; n = n->next) {
                if (n->key == key) {
                    n->value = value;
                    return;
                }
            }
            head = new Node(key, value, head);
        }
        char get(int key) {
            for (Node *n = head; n != NULL; n = n->next) {
                if (n->key == key) {
                    return n->value;
                }
            }
            throwNoSuchKey(key);
        }
};
