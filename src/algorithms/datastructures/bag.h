#ifndef BAG_H
#define BAG_H
#include "linkedlist.cpp"

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
        NodeIterator<int>* iterator();
};
#endif
