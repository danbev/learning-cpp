#include <iostream>
#include <string>

int binarysearch(char arr[], int length, char key) {
    int low = 0;
    int high = length;
    while (low <= high) {
        int mid = low + (high-low) / 2;
        if (key < arr[mid]) {
            high = mid - 1;
        } else if (key > arr[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -(low+1);
}

