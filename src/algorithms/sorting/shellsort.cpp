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
