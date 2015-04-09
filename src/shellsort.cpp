#include <stdio.h>
#include "sort.hpp"

int main() {
    int unsorted[] = {4, 1, 2, 3};
    int len = 4;
    int *sorted = shell_sort(unsorted, len);
    for (int i = 0 ; i < len; i++) {
        printf("%d", sorted[i]);
    }
    printf("\n");
}
