#include "linkedlist.cpp"
#ifndef BAG_H
#define BAG_H

/*
 * A datastructure that can only be added into.
 */
class Bag {
    private:
        LinkedList* list;
    public:
        Bag();
        ~Bag();
        int size() const;
        Bag& add(int value);
        template<class Func>
        void foreach(Func &f) const;
        IntIterator* iterator();
};
#endif
