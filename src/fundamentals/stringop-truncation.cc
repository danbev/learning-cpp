#include <string>
#include <cstring>
#include <stdio.h>

int main(int argc, char** argv) {
  printf("-Wstringop-truncation example\n");

  char dst[157] = {0};

  // string literals contain a null-terminator.
  const char* src = "bajja";
  // strlen does not include the terminating null byte ('\0').
  int32_t len = strlen(src);
  printf("src len: %d\n", len);
  printf("dst len: %ld\n", strlen(dst));

// If the intention is to not write the null-terminator byte then this
// warning can be ignored:
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstringop-truncation"
  strncpy(dst, src, len+1);
#pragma GCC diagnostic pop

  // Or we should include the null-terminator byte:
  strncpy(dst, src, len+1);

  printf("dst: %s\n", dst);

  return 0;
}
