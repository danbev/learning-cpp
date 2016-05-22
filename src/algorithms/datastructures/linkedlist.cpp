#include <iostream>
#ifndef LINKED_LIST
#define LINKED_LIST
#include "iterator.h"

template<typename T = int>
class LinkedList {
    private: 
        Node<T>* head;
        int length;
    public:
        LinkedList<T>();
        bool empty() const;
        LinkedList<T> &addFront(T value);
        T removeFront();
        T front() const;
        int size() const;
        bool contains(T nr) const;
        const LinkedList<T> &print() const;
        template<class Func>
        void foreach(Func &f) const;
        Iterator<T>* iterator();
};


template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), length(0) {
}

template<typename T>
bool LinkedList<T>::empty() const {
    return head == nullptr;
}

template<typename T>
LinkedList<T>& LinkedList<T>::addFront(T value) {
    Node<T>* newNode = new Node<T>(value, nullptr);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T>* current = head;
        newNode->next(current);
        head = newNode;
    }
    length++;
    return *this;
}

template<typename T>
T LinkedList<T>::removeFront() {
    if (head == nullptr) {
        return -1;
    }
    Node<T> *old = head;
    head = old->next();
    T value = old->value();
    delete old;
    length--;
    return value;
}

template<typename T>
T LinkedList<T>::front() const {
    if (head == nullptr) {
        return -1;
    }
    return head->next()->value();
}

template<typename T>
int LinkedList<T>::size() const {
    return length;
}

template<typename T>
bool LinkedList<T>::contains(T nr) const {
    if (head == nullptr) {
        return false;
    }
    for (Node<T>* p = head; p != nullptr; p = p->next()) {
        if (p->value() == nr) {
            return true;
        }
    }
    return false;
}

template<typename T>
const LinkedList<T>& LinkedList<T>::print() const {
    if (head == nullptr) {
        std::cout << "[empty]" << std::endl;
    } else {
        std::cout << "[";
        for (Node<T>* node = head; node != nullptr; node = node->next()) {
            std::cout << ", " << node->value();
        }
        std::cout << "]" << std::endl;
    }
    return *this;
}

// the class template must come first it seems or you'll get a :
// error: nested name specifier 'LinkedList<T>::' for declaration does not refer into a class, class
//       template or class template partial specialization
//       void LinkedList<T>::foreach(Func &f) const {
template<typename T>
template<class Func>
void LinkedList<T>::foreach(Func &f) const {
    if (empty()) {
        return;
    }
    for (Node<T>* node = head; node != nullptr; node = node->next()) {
        f(node->value());
    }
}

/*
template<typename T>
Iterator<T>::Iterator(Node<T>* current) {
    this->current_ = current;
}

template<typename T>
T Iterator<T>::next() {
    T v = current_->value();
    current_ = current_->next();
    return v;
}

template<typename T>
bool Iterator<T>::hasNext() {
    return current_ != nullptr;
}
*/

template<typename T>
Iterator<T>* LinkedList<T>::iterator() {
    return new Iterator<T>(head);
}

/*
 * Reverses the passed in array using the LinkedList
 */ 
/*
template<typename T>
void LinkedList<T>::reverseArray(T arr[], int size) const {
    LinkedList<T> list;
    for (T i = 0; i < size; i++) {
        list.addFront(arr[i]);
    }
    for (T i = 0; i < size; i++) {
        arr[i] = list.removeFront();
    }
}
*/
#endif
