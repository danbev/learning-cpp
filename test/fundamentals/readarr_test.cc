#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

TEST(ReadArr, auto_refs) {
  ifstream cas;
  cas.open("fundamentals/sample.crt", ios::in);
  string line;
  int count = 0;
  if (cas.is_open()) {
    cout << "file is open..." << '\n';
    while (getline(cas, line)) {
      if (line == "-----BEGIN CERTIFICATE-----") {
        count++;
      }
      cout << line << '\n';
    }
  } else {
    cout << "could not open file..." << '\n';
  }
  cout << "count: " << count << '\n';
  EXPECT_EQ(count, 2);
  cas.close();
}
