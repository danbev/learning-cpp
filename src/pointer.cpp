#include <iostream>

void doit(const int *p) {
    printf("%d\n", *p);
}

int main() {
    int p = 10;
    int *p1 = &p;
    printf("Value of p %d\n", p);
    printf("Address of p %p\n", &p);
    printf("Value of *p1 %d\n", *p1);
    printf("Address p1 %p\n", p1);
    const int *cp1 = p1;
    doit(cp1);
}
