#ifndef NODE_ITERATOR
#define NODE_ITERATOR
#include "node.h"
template<typename T>
class NodeIterator {
    protected:
        Node<T>* current_;
    public:
        NodeIterator(Node<T>* current);
        T next();
        bool hasNext();
};

template<typename T>
NodeIterator<T>::NodeIterator(Node<T>* current) : current_(current) {
}

template<typename T>
T NodeIterator<T>::next() {
    T v = current_->value_;
    current_ = current_->next_;
    return v;
}

template<typename T>
bool NodeIterator<T>::hasNext() {
    current_ != nullptr;
}

#endif
