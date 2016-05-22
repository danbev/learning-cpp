#ifndef ITERATOR
#define ITERATOR
#include "node.h"
template<typename T>
class Iterator {
    protected:
        Node<T>* current_;
    public:
        Iterator(Node<T>* current);
        T next();
        bool hasNext();
};

template<typename T>
Iterator<T>::Iterator(Node<T>* current) : current_(current) {
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

#endif
