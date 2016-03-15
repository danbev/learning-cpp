#include <stdio.h>
#include <string>
#include "sequential-symbol-table.cpp"

/* 
 * HashTable implementation that uses chaining for collision 
 * resolution.
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
            this->table = new SequentialSymbolTable*[size] {NULL};
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
    if (list == NULL) {
        list = new SequentialSymbolTable();
        table[h] = list;
    }
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
