#include <stdio.h>
#include "sort.hpp"

int main() {
    int unsorted[] = {2, 4, 1, 5, 3};
    int len = 5;
    int *sorted = bubble_sort(unsorted, len);
    for (int i = 0 ; i < len; i++) {
        printf("%d", sorted[i]);
    }
    printf("\n");
}
