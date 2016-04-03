#include "iterator.h"
#ifndef INT_ITERATOR
#define INT_ITERATOR
class IntIterator: public Iterator<int> {
    public:
        virtual int next() const = 0;
        virtual bool hasNext() const = 0;
};
#endif
