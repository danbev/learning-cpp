#ifndef BAG
#define BAG
#include "bag.h"

template<typename T>
Bag<T>::Bag() {
    this->list = new LinkedList<T>();
}

template<typename T>
Bag<T>::~Bag() {
    delete list;
}

template<typename T>
int Bag<T>::size() const {
    return list->size();
}

template<typename T>
Bag<T>& Bag<T>::add(T value) {
    list->addFront(value);
    return *this;
}
template<typename T>
template<class Func>
void Bag<T>::foreach(Func &f) const {
    list->foreach(f);
}

template<typename T>
Iterator<T>* Bag<T>::iterator() {
    return list->iterator();
}
#endif
