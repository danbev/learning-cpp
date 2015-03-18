#include "sort.hpp"
#include <stdio.h>

void printArray(int arr[], size_t len) {
    printf("Array:");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int* bubble_sort (int arr[], size_t len) {
    // keep track of the passes over the array. So start with 1 and not 0
    for (int i = 1; i < len; i++) {
        printArray(arr, len);
        printf("pass=%d\n", i);
        // loop through but only up to the last bubbled up value. We only need to check and potentially swap those
        // values that have not already been placed into their final slot.
        for (int j = 0; j < len - i; j++) {
            int right = j+1;
            printf("%d > %d", arr[j], arr[right]);
            if (arr[j] > arr[right]) {
                printf(" swap\n");
                int tmp = arr[j];
                arr[j] = arr[right];
                arr[right] = tmp;
            } else {
                printf("\n");
            }
        }
    }
    return arr;
}

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

