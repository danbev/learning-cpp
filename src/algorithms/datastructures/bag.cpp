#include <stdio.h>

class Bag {
    private:
        int * items;
        int n;
        int count;
    public:
        Bag(int size) {
            this->n = size;
            this->items = new int[size] {0};
            this->count = 0;
        }
        ~Bag() {
            delete [] items;
        }
        int capacity() {
            return n;
        }
        int size() {
            return count;
        }
        Bag* add(int value) {
            if (count == n) {
                throw "Bag is full";
            }
            items[count++] = value;
            return this;
        }
        template<class Func>
        void foreach(Func &f) {
            if (count == 0) {
                return;
            }
            for (int i = 0; i < count; i++) {
                f(items[i]);
            }
        }
};
