#include <random>    

void randomize(int *arr, int n) {
    std::random_device rd;
    std::mt19937 mt(rd()); 
    std::uniform_int_distribution<int> dist(0, n);

    for (int i=0; i < n; i++) {
        int r = dist(mt) % n;
        int temp = arr[i]; 
        arr[i] = arr[r]; 
        arr[r] = temp;
    }
}
