#include <stdio.h>
#include "selectionsort.hpp"

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
