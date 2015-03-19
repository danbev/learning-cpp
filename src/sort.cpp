#include "sort.hpp"
#include <stdio.h>

void printArray(int arr[], size_t len) {
    printf("Array:");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

/*
 * Worst case complexity is O(n^2)
 * When the array is already sorted the complexity is O(n)
 */
int* bubble_sort (int arr[], size_t len) {
    // keep track of the passes over the array, starting with one. O(n)
    for (int i = 1; i < len; i++) {
        bool swapped = false;
        // first pass N-1 comparisions, second pass N-2 comparisions...N*(N-1)/2. 5*(5-1)/2 = 20/2 = 10
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

int* insertion_sort (int arr[], size_t len) {
    // keep track of the passes over the array, starting with one. O(n)
    for (int i = 1; i < len; i++) {
        // keep a marker j to divide the array into a left and right side. 
        // the items to the left are sorted and the items to the right are unsorted.
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
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i+1; j < len; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
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

