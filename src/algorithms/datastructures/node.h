#ifndef NODE_H
#define NODE_H
template<typename T>
class Node {
    protected:
        T value_;
        Node<T>* next_;
    public:
        Node(T value, Node* next);
        ~Node();
        T value();
        virtual Node* next();
        virtual void next(Node<T>* next);
};

template<typename T>
Node<T>::Node(T value, Node<T>* next) : value_(value), next_(next) {
}

template<typename T>
Node<T>::~Node() {
}

template<typename T>
T Node<T>::value() {
    return value_;
}

template<typename T>
Node<T>* Node<T>::next() {
    return next_;
}

template<typename T>
void Node<T>::next(Node<T>* next) {
    next_ = next;
}

#endif
