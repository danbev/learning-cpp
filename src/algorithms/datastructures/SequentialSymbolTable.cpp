#include <stdio.h>
#include <string.h>

/*
 * Sequential symbol table that uses a singely linked list.
 * This is one of the basic implementations of symbol tables
 * which are mainly to point out the weakness with them, and
 * help understanding the more complex implementations.
 * I've currently only implemented get/put.
 */
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
