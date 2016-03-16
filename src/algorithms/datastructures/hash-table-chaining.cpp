#include <stdio.h>
#include <string>
#include "sequential-symbol-table.cpp"

/* 
 * HashTable implementation that uses chaining for collision 
 * resolution.
 *
 * worst-case cost      average-case cost
 * search: < lg N       N/(2M)
 * insert: < lg N       N/M
 *
 * N = items
 * M = number of lists (each entry in the array is a list)
 *
 * Since we have M lists and N keys the average length of the lists
 * is always N/M.
 * https://gist.github.com/danbev/076ca6efcd790f1fbf1e
 *
 * In a separate-chaining hash table with M lists and N keys, the probability
 * that the number of keys in a list is within a small constant factor of N/M
 * is extremely close to 1. The number of compares  (equality tests) for search
 * miss and insert is ~N/M.
 *
 * So let say we have an array of size 10 and have 6 items inserted
 * that could give an average insert cost of 6/10 = 0.6
 *
 */
class HashTable {
    private:
        int size;
         SequentialSymbolTable** table;
         int hash(int key);
    public:
        HashTable(int size) { 
            this->size = size;
            this->table = new SequentialSymbolTable*[size] {};
            for (int i = 0; i < size; i++) {
                this->table[i] = new SequentialSymbolTable();
            }
        };
        ~HashTable() {
            for (int i = 0; i < size; i++) {
                if (table[i] != NULL) {
                    delete table[i];
                }
            }
            delete [] table;
        };
        int getSize();
        void put(int key, char value);
        char get(int key);
};

int HashTable::getSize() {
    return size;
}

void HashTable::put(int key, char value) {
    int h = hash(key);
    SequentialSymbolTable* list = table[h];
    list->put(key, value);
}

char HashTable::get(int key) {
    int h = hash(key);
    SequentialSymbolTable* list = table[h];
    if (list == NULL) {
        throw "Key iiinot found : " + std::to_string(key);
    }

    return list->get(key);
}

int HashTable::hash(int key) {
    return key % size;
}
