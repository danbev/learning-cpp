#include <cstring>
#include <iostream>

bool contains(char *str, char *pat) {
  int s = strlen(str);
  int p = strlen(pat);
  std::cout << "str=" << str << "[" << s << "], pat=" << pat << "[" << p << "]" << std::endl;
  for (int i = 0; i <= s - p ; i++) {
    int j;
    for (j = 0; j < p; j++) {
      if (str[i+j] != pat[j]) {
        break;
      }
    }
    if (j == p) {
      return true;
    }
  }
  return false;
}
