#include <gtest/gtest.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

TEST(Malloc, malloc) {
  const char* name = "node";
  const char* arg1 = "-e";
  const char* arg2 = ";";

  char **argv = (char**) malloc(3 * sizeof(char*));
  argv[0] = (char*) malloc(strlen(name) + 1 + strlen(arg1) + 1 + strlen(arg2));
  strcpy(argv[0], name);
  strcpy(argv[0] + strlen(name) + 1, arg1);
  strcpy(argv[0] + strlen(name) + 1 + strlen(arg1) + 1, arg2);
  //cout << &argv[0] << endl;
  //cout << &argv[1] << endl;
  //cout << &argv[2] << endl;
  EXPECT_STREQ(argv[0], name);
  EXPECT_STREQ(argv[0] + strlen(name) + 1, arg1);
  EXPECT_STREQ(argv[0] + strlen(name) + 1 + strlen(arg1) + 1, arg2);
}

