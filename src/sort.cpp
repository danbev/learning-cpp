#include "sort.hpp"
#include <stdio.h>

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

// So we our going to sort the array in 'h' groups. Say we set h to 4 then every 4th value is part of 
// one group.
int* shell_sort (int arr[], size_t len) {
    int h = 1;
    while (h < len / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        printf("h=%d\n", h);
        for (int i = h; i < len; i++) {
            printf("i=%d\n", i);
            for (int j = i; j >= h && arr[j] < arr[j-h]; j -= h) {
                int tmp = arr[j];
                arr[j] = arr[j-h];
                arr[j-h] = tmp;
            }
        }
        h /= 3;
    }
    return arr;
}

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



