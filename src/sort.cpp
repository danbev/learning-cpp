#include "sort.hpp"
#include <stdio.h>

int* insertion_sort (int arr[], size_t len) {
    for (int i = 1; i < len; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j-1]; j--) {
            int tmp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = tmp;
        }
    }
    return arr;
}

// Works by repeatedly selecting the smallest remaining value.
int* selection_sort (int arr[], size_t len) {
    // first loop through the entire array. O(n)
    for (int i = 0; i < len; i++) {
        // store the min position
        int min = i;
        // find the min value in the remaining entries of the array. O(n)
        for (int j = i+1; j < len; j++) {
            // if the current value being checked is less that the stored min, set that value as min
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        // now swap the current items value with the min value found in the array
        // first store the current value as we need to overwrite it with the found min value
        int tmp = arr[i];
        // store the found min value in the current position
        arr[i] = arr[min];
        // store the value that was in the current position with the location where the min value was taken from
        arr[min] = tmp;
    }
    // O(n * n) = O(n^2)
    return arr;
}

// Works by repeatedly selecting the largest remaining value.
int* selection_sort_rev(int arr[], size_t len) {
    for (int i = 0; i < len; i++) {
        int max = i;
        for (int j = i+1; j < len; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[max];
        arr[max] = tmp;
    }
    return arr;
}
