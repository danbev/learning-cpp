#include "search.hpp"

int binarysearch (int arr[], int length, int key) {
    int low = 0;
    int high = length;
    while (low < high) {
        int mid = low + (high-low) / 2;
        if (key < arr[mid]) {
            high = mid;
        } else if (key > arr[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -(low+1);
}
