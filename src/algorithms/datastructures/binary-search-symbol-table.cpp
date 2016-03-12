#include <stdio.h>

/*
 * This is the second of the basic symbol table implementations, 
 * with SequentialSymbolTable being the first.
 *
 * This symbol table a pair of arrays as its underlying datastructure
 * and then uses binary search for get/put.
 *
 * This choice is far better than the sequential search symbol table
 * and good choice for static tables (no inserts allowed).
 * If the use case requires fast implementations of both search and 
 * insert than this is not the right choice. Take a look at 
 * symbol table based on a binary search tree for that.
 *
 * worst-case cost      average-case cost
 * search: lg N         lg N
 * insert: 2N           N
 *
 */
class BinarySearchSymbolTable {
    private: 
        int *keys;
        char *values;
        int size = 0;
        int length;
    public:
        BinarySearchSymbolTable(int length) {
            this->keys = new int[length];
            for (int i = 0; i < length; i++) {
                this->keys[i] = -1;
            }
            this->values = new char[length];
            for (int i = 0; i < length; i++) {
                this->values[i] = -1;
            }
            this->length = length;
        }
        ~BinarySearchSymbolTable() {
            delete [] this->keys;
            delete [] this->values;
        }

       BinarySearchSymbolTable& put(int key, char value) {
            int i = rank(key, 0, size-1);
            // if the rank is less than the lenght of the array, and
            // is equal to the key being inserted in which case we simply
            // update it value.
            if (i < length && keys[i] == key) {
                values[i] = value;
            } else {
                // now, the key does not exist so we need to insert it. But since we are
                // using binary search we need to have the array in sorted order. 
                // let say we put 0:a, 2:c
                // keys   = [0, 2]
                // values = [a, c]
                // Next, we put 1:b
                // rank will return 1 for this put but this slot is already taken. We'll have 
                // to move all the entries from the rank upto the current size.
                for (int j = size; j > i; j--) {
                    keys[j] = keys[j-1];
                    values[j] = values[j-1];
                }
                keys[i] = key;
                values[i] = value;
                size++;
            }
            return *this;
        }

        char get(int key) {
            int i = rank(key, 0, size-1);
            if (i < length && keys[i] == key) {
                return values[i];
            }
            throw "Not round";
        }

        /*
         * If the key exists then rank returns the index corresponding 
         * to the key.
         * If the key docs not exist, the retuned value represents the
         * number of keys smaller than the key.
         */
        int rank(int key, int low, int high) {
            if (high < low) {
                return low;
            }
            int mid = low + (high-low) /2;
            if (key < keys[mid]) {
                return rank(key, low, mid - 1);
            } else if (key > keys[mid]) {
                return rank(key, mid + 1, high);
            } else {
                return mid;
            }
        }

        BinarySearchSymbolTable& print() {
            std::cout << '[';
            int end = size-1;
            for (int i = 0; i < end; i++) {
                std::cout << keys[i] << ':' << values[i] << ", ";
            }
            std::cout << keys[end] << ':' << values[end] << ']' << std::endl;
            return *this;
        }

};
