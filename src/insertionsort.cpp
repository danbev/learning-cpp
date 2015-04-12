#include <stdio.h>
#include "insertionsort.hpp"

void printArray(int arr[], size_t len) {
    printf("Array:");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void printArr(int *p, size_t len) {
    printf("Array:");
    for (int i = 0; i < len; i++) {
        printf("%d", *(p + i));
    }
    printf("\n");
}

int* insertion_sort (int arr[], size_t len) {
    // keep track of the passes over the array, starting with one. O(n)
    for (int i = 1; i < len; i++) {
        // j is our "marker" for the already sorted items. 
        // On the first pass we are comparing the current item 'i'.
        // On the next passes we are checking if any of the already sorted items need swapping.
        for (int j = i; j > 0 && arr[j] < arr[j-1];j--) {
            int tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
        }
    }
    return arr;
}

int main() {
    int unsorted[] = {4, 1, 2, 3};
    int len = 4;
    int *sorted = insertion_sort(unsorted, len);
    for (int i = 0 ; i < len; i++) {
        printf("%d", sorted[i]);
    }
    printf("\n");
}

