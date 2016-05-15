#ifndef DNODE_H
#define DNODE_H
template<typename T>
class DNode : public Node<T> {
    protected:
        DNode<T>* previous_;
        DNode<T>* next_;
    public:
        DNode(T value, DNode<T>* next, DNode<T>* previous);
        ~DNode();
        DNode* next();
        void next(DNode<T>* next);
        DNode* previous();
        void previous(DNode<T>* previous);
};

template<typename T>
DNode<T>::DNode(T value, DNode<T>* next, DNode<T>* previous) : Node<T>(value, next) {
    next_ = next;
    previous_ = previous;
}

template<typename T>
DNode<T>::~DNode() {
}

template<typename T>
DNode<T>* DNode<T>::next() {
    return next_;
}

template<typename T>
void DNode<T>::next(DNode<T>* next) {
    next_ = next;
}

template<typename T>
DNode<T>* DNode<T>::previous() {
    return previous_;
}

template<typename T>
void DNode<T>::previous(DNode<T>* previous) {
    previous_ = previous;
}

#endif
