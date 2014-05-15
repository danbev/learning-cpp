#include <iostream>
#include <string>

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
    return -(low);
}

int main() {
    int sorted[6] = {1, 2, 3, 4, 5, 6};
    int length = 6;
    std::cout << "arr = {";
    for (int i : sorted) {
        std::cout << i << ",";
    }
    std::cout << "}" << std::endl;
    std::cout << "Binary search for 1 = " << binarysearch(sorted, length, 1) << std::endl;
    std::cout << "Binary search for 2 = " << binarysearch(sorted, length, 2) << std::endl;
    std::cout << "Binary search for 3 = " << binarysearch(sorted, length, 3) << std::endl;
    std::cout << "Binary search for 4 = " << binarysearch(sorted, length, 4) << std::endl;
    std::cout << "Binary search for 5 = " << binarysearch(sorted, length, 5) << std::endl;
    std::cout << "Binary search for 6 = " << binarysearch(sorted, length, 6) << std::endl;
    std::cout << "Binary search for 7 = " << binarysearch(sorted, length, 7) << std::endl;
    return 0;
}


