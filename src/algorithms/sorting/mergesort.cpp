#include <stdio.h>
#include "mergesort.hpp"

void merge(int arr[], size_t len, int aux[], int low, int mid, int high) {
    // i = position in left side, j = position in right side, and k = position in arr.
    int i, j, k;
    for (i = mid + 1; i > low; i--) {
        aux[i-1] = arr[i-1];
    }
    for (j = mid; j < high; j++) {
        aux[high + mid - j] = arr[j+1];
    }
    for (k = low; k <= high; k++) {
        if (aux[i] < aux[j]) {
            arr[k] = aux[i++];
        } else {
            arr[k] = aux[j--];
        }
    }
}

void mergeSort(int arr[], size_t len, int aux[], int low, int high) {
    if (low == high) {
        return;
    }
    int mid = low + (high-low) / 2;
    mergeSort(arr, len, aux, low, mid);
    mergeSort(arr, len, aux, mid + 1, high);
    merge(arr, len, aux, low, mid, high);
}

int* merge_sort(int arr[], size_t len) {
    int aux[10] = {0};
    mergeSort(arr, len, aux, 0, len);
    return arr;
}

