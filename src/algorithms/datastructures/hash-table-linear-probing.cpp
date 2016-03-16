#include <stdio.h>
#include <string>

/* 
 * HashTable implementation that uses linear probing as its
 * collision resolution policy.
 *
 * This is a strategy called Open Addressing where we simply use
 * an array. 
 * So we first hash the key and then insert it into the array. If a
 * collision occurs we simply add the key to the next empty slot in
 * the array. When searching we start at the hashed value and then
 * compare each slot until we find the key or reach an empty slot.
 *
 * There is no array resizing being done at the moment.
 *
 * If the size of the array is too large there will be many empty entries
 * If the size of the array is too small search times will suffer as there
 * will be longer and longer clusters of full entries which have to be gone
 * through.
 *
 * Primary clustering:
 * Beginning with an empty array of size 10 (N) we can see that inserting a key
 * has the chance of ending up in any slot in the array:
 * 1/N  1/N  1/N  1/N  1/N  1/N  1/N  1/N  1/N  1/N
 * [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ] 
 *  0    1    2    3    4    5    6    7    8    9
 * Lets insert 24 % 10 = 4 key:
 * 1/N  1/N  1/N  1/N   0   2/N  1/N  1/N  1/N  1/N
 * [ ]  [ ]  [ ]  [ ]  [24] [ ]  [ ]  [ ]  [ ]  [ ] 
 *  0    1    2    3    4    5    6    7    8    9
 * There is an increased chance slot 5 be filled next time and a cluster
 * formed. This increases as the cluster grows and clusters may also merge
 * causing even larger clusters.
 * There other open addressing strategies that avoid this issue with clusters.
 */
class HashTable {
    private:
        int size;
        int * table;
        char * values;
        int hash(int key);
    public:
        HashTable(int size) { 
            this->size = size;
            this->table = new int[size];
            this->values = new char[size];
            for (int i = 0; i < size; i++) {
                table[i] = -1;
                values[i] = -1;
            }
        };
        ~HashTable() {
            delete [] table;
            delete [] values;
        };
        int getSize();
        void put(int key, char value);
        char get(int key);
};

int HashTable::getSize() {
    return size;
}

void HashTable::put(int key, char value) {
    int i;
    for (i = hash(key); table[i] != -1; i = (i+1) % size) {
        if (table[i] == key) {
            break;
        }
    }
    table[i] = key;
    values[i] = value;
}

char HashTable::get(int key) {
    for (int i = hash(key); table[i] != -1; i = (i+1) % size) {
        if (table[i] == key) {
            return values[i];
        }
    }
    return -1;
}

int HashTable::hash(int key) {
    return key % size;
}
