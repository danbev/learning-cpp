#include <cstdlib>

int main(int argc, char** argv) {
  // malloc(0) will either return a null pointer or a unique pointer
  // that can be freed.
  int* ptr = (int*) malloc(0);
  // remember that delete is for memory allocated with 'new' or for nullptr.
  free(ptr);
  return 0;
}
