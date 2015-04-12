#include <stdio.h>
#include "shellsort.hpp"

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

int main() {
    int unsorted[] = {4, 1, 2, 3};
    int len = 4;
    int *sorted = shell_sort(unsorted, len);
    for (int i = 0 ; i < len; i++) {
        printf("%d", sorted[i]);
    }
    printf("\n");
}
