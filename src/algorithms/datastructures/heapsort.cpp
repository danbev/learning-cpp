#include <iostream>
#include "binaryheap.cpp"

/*
 * In-place (no extra array) sorting algorithm with N log N worst-case
 *
 * Take away:
 * - Is optimal for both time and space but the inner loop performs more things than
 * quicksort. 
 * - Also it makes poor use of cache memory (looks far away for the next item)
 * - Not stable
 */
class HeapSort {
    private:
        void print(char *a, int n) {
            int end = n-1;
            std::cout << "a[";
            for (int i = 0; i < end; i++) {
                std::cout << a[i] << ",";
            }
            std::cout << a[end] << "]" << std::endl;
        }
    public:
        void sort(char *a, int n) {
        // make the array heap ordered.
        // start from  parent of the last node which is n/2, and make that tree heap ordered.
        print(a, n);
        for (int k = n/2; k >= 0; k--) {
            BinaryHeap::reheapifyDown(k, a, n);
        }
        print(a, n);

        // Now, what we are going to do is take the max value, position a[1] and exchange it with the
        // last value in the array. We remove this value from the heap.
        int end = n-1;
        while (end >= 1) {
            char max = a[0];
            BinaryHeap::swap(0, end--, a); 
            // this is not optimal, but this could be addressed using a decicated reheapifyDown method
            // especially for this class. If this were "real" code that would be doing.
            if (end == 0) {
                break;
            }
            BinaryHeap::reheapifyDown(0, a, end);
        }
        print(a, n);
    }
};
