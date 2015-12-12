#include <cstring>
#include "StringBad.h"

using std::cout;

int StringBad::nrStrings = 0;

StringBad::StringBad() {
  len = 4;
  std::strcpy(str, "C++");
  nrStrings++;
  cout << nrStrings << ":\"" << str << "\" object created (no args constructor)\n";
}

StringBad::StringBad(const char *s) {
  len = std::strlen(s);
  str = new char[len+1];
  std::strcpy(str, s);
  nrStrings++;
  cout << nrStrings << ":\"" << str << "\" object created\n";
}

StringBad::StringBad(const StringBad &sb) {
  cout << ":\"" << sb.str << "\" created using Copy Constructor\n";
  // simulate the default copy constructor
  str = sb.str;
  len = sb.len;
}

StringBad::~StringBad() {
  cout << ":\"" << str << "\" object delected\n";
  --nrStrings;
  cout << nrStrings << " left\n";
  delete []str;
}

std::ostream & operator<<(std::ostream &os, const StringBad &s) {
  os << s.str;
  return os;
}

