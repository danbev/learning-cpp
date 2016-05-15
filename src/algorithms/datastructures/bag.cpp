#include <stdio.h>
#include "bag.h"

Bag::Bag() {
    this->list = new LinkedList();
}

Bag::~Bag() {
    delete list;
}

int Bag::size() const {
    return list->size();
}

Bag& Bag::add(int value) {
    list->addFront(value);
    return *this;
}
template<class Func>
void Bag::foreach(Func &f) const {
    list->foreach(f);
}

NodeIterator<int>* Bag::iterator() {
    return list->iterator();
}
