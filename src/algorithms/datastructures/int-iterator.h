#include "iterator.h"
#ifndef INT_ITERATOR
#define INT_ITERATOR
class IntIterator: public Iterator<int> {
    public:
        virtual int next() = 0;
        virtual bool hasNext() = 0;
};
#endif
