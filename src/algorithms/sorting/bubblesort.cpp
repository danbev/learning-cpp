#include <stdio.h>
#include "bubblesort.hpp"

/*
 * Worst case complexity is O(n^2)
 * When the array is already sorted the complexity is O(n)
 */
int* bubble_sort (int arr[], size_t len) {
    for (int i = 1; i < len; i++) {
        bool swapped = false;
        for (int j = 0; j < len - i; j++) {
            int next = j+1;
            if (arr[j] > arr[next]) {
                int tmp = arr[j];
                arr[j] = arr[next];
                arr[next] = tmp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return arr;
}

