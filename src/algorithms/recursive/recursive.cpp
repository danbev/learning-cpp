#include "recursive.hpp"
#include <stdio.h>

int triangle(int n) {
    if (n == 1) {
        return n;
    }
    return (n + triangle(n - 1));
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return (n * factorial(n - 1));
}

