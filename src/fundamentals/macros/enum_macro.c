#include "enum_macro.h"
#include <stdio.h>

const char* get_status(napi_status status) {
  return status_strings[status];
}

int main(void) {
  printf("status: %s\n", get_status(napi_ok));
  printf("status: %s\n", get_status(napi_cancelled));
  return 0;
}
