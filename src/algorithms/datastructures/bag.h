#ifndef BAG_H
#define BAG_H
#include "linkedlist.cpp"

/*
 * A datastructure that can only be added into.
 */
template<typename T = int>
class Bag {
    private:
        LinkedList<T>* list;
    public:
        Bag();
        ~Bag();
        int size() const;
        Bag<T>& add(T value);
        template<class Func>
        void foreach(Func &f) const;
        Iterator<T>* iterator();
};
#endif
