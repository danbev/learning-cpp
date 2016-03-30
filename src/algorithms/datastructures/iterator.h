#ifndef ITERATOR
#define ITERATOR
template<typename T>
class Iterator {
    public:
        T next();
        bool hasNext();
};
#endif
