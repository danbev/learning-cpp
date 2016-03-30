#include <stdio.h>
#include "linkedlist.cpp"

/*
 * A datastructure that can only be added into.
 */
class Bag {
    private:
        LinkedList* list;
    public:
        Bag() {
            this->list = new LinkedList();
        }
        ~Bag() {
            delete list;
        }
        int size() {
            return list->size();
        }
        Bag& add(int value) {
            list->addFront(value);
            return *this;
        }
        template<class Func>
        void foreach(Func &f) {
            list->foreach(f);
        }
        IntIterator* iterator() {
            return list->iterator();
        }
};
