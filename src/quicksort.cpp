#include <stdio.h>
#include "quicksort_header.hpp"

int* _quick_sort(int arr[], int left, int right);

int* quick_sort(int arr[], int len) {
    return _quick_sort(arr, 0, len -1);
}

int partition(int arr[], int left, int right) {
    int p = right;
    int firstHigh = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < arr[p]) {
            int tmp = arr[i];
            arr[i] = arr[firstHigh];
            arr[firstHigh] = tmp;
            firstHigh++;
        }
    }
    // since we have swapped all that are less than the pivot we can swap the firstHigh
    // with the pivot.
    int tmp = arr[p];
    arr[p] = arr[firstHigh];
    arr[firstHigh] = tmp;
    return firstHigh;
}

int* _quick_sort(int arr[], int left, int right) {
    if (right <= left) {
        return arr;
    }
    int p = partition(arr, left, right);
    _quick_sort(arr, left, p-1);
    _quick_sort(arr, p+1, right);
    return arr;
}


int main() {
    int unsorted[] = {4, 2, 1, 3};
    int len = 4;
    int *sorted = quick_sort(unsorted, len);
    for (int i = 0 ; i < len; i++) {
        printf("%d", sorted[i]);
    }
    printf("\n");
}
