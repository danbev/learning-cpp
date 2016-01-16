#include <stdio.h>
#include <math.h>

void merge(int arr[], int aux[], int low, int mid, int high) {
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

/*
 * You can think of this process of the initial array being in small array of size 1.
 * The second iteration will separate them arrays of size 2 which will be merged
 */
int * mergesort(int arr[], size_t n) {
  int aux[n];
  for (int i = 1; i < n; i = i + i) {
    for (int low = 0; low < n-i; low += i + i) {
      int mid = low + i -1;
      int high =  fmin(low + i + i - 1, n-1);
      merge(arr, aux, low, mid, high);
    }
  }
  return arr;
}

