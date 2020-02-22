#include <stdio.h>

__attribute__ ((constructor)) void bajja(int argc) {
  printf("bajja is running: argc=%d\n", argc);
}

__attribute__ ((destructor)) void bajjad(void) {
  printf("bajja is ending\n");
}
 
int main(int argc, char** argv) {
  printf("%s: main...\n", argv[0]);
}
