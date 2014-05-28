#include "sort.hpp"

int* insertion_sort (int arr[], int len) {
    for (int i = 1; i < len; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j-1]; j--) {
            int tmp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = tmp;
        }
    }
    return arr;
}
