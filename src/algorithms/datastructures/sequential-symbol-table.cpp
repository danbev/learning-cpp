#include <stdio.h>
#include <string.h>

/*
 * Sequential symbol table that uses a singely linked list.
 * This is one of the basic implementations of symbol tables
 * which are mainly to point out the weakness with them, and
 * help understanding the more complex implementations.
 * I've currently only implemented get/put.
 *
 *
 * worst-case cost          average-case cost
 * search:  N               N/2
 * insert:  N               N
 *
 */
template <typename K, typename V>
class Node {
    template <typename X, typename Y>
    friend class SequentialSymbolTable;
    private: 
        K key;
        V value;
        Node *next;
    public:
        Node(K key, V value, Node *next = nullptr);
        ~Node() {};
};

template <typename K, typename V>
Node<K,V>::Node(K key, V value, Node<K,V> *next) {
    this->key = key;
    this->value = value;
    this->next = next;
}

template <typename K, typename V>
class SequentialSymbolTable {
    private:
        Node<K,V> *head;
    public:
        SequentialSymbolTable() :head(nullptr) {};
        void put(K key, V value);
        V get(K key);
};

template <typename K, typename V>
void SequentialSymbolTable<K,V>::put(K key, V value) {
    for (Node<K,V> *n = head; n != nullptr; n = n->next) {
        if (n->key == key) {
            n->value = value;
            return;
        }
    }
    head = new Node<K,V>(key, value, head);
}

template <typename K, typename V>
V SequentialSymbolTable<K,V>::get(K key) {
    for (Node<K,V> *n = head; n != nullptr; n = n->next) {
        if (n->key == key) {
            return n->value;
        }
    }
    throw "No such key";
}
