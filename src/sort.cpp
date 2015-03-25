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

void merge(int arr[], size_t len, int low, int mid, int high) {
    int* s = new int[len];
    int i, j, k;
    for (i = mid + 1; i > low; i--) {
        s[i-1] = arr[i-1];
    }
    for (j = mid; j < high; j++) {
        s[high + mid - j] = arr[j+1];
    }
    for (k = low; k <= high; k++) {
        if (s[i] < s[j]) {
            arr[k] = s[i++];
        } else {
            arr[k] = s[j--];
        }
    }
}

void mergeSort(int arr[], size_t len, int low, int high) {
    if (low == high) {
        return;
    }
    int mid = low + (high-low) / 2;
    mergeSort(arr, len, low, mid);
    mergeSort(arr, len, mid + 1, high);
    merge(arr, len, low, mid, high);
}

int* merge_sort(int arr[], size_t len) {
    mergeSort(arr, len, 0, len - 1);
    return arr;
}



