#include <cstring>
#include "StringBad.h"

using std::cout;

int StringBad::nrStrings = 0;

StringBad::StringBad() {
  len = 4;
  str = new char[len+1];
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
  cout << nrStrings << ":\"" << sb.str << "\"  created using Copy Constructor\n";
  len = sb.len;
  nrStrings++;
  // simulate the default copy constructor
  //str = sb.str;
  str = new char[len+1];
  std::strcpy(str, sb.str);
}

StringBad::~StringBad() {
  cout << nrStrings <<  ":\"" << str << "\" object deleted\n";
  --nrStrings;
  cout << nrStrings << " left\n";
  delete []str;
}

StringBad & StringBad::operator=(const StringBad &sb) {
  if (this == &sb) {
    return *this;
  }
  cout <<  "operator= str was=" << str << " is now=" << sb.str << std::endl;
  delete [] str;
  len = sb.len;
  str = new char[len+1];
  std::strcpy(str, sb.str);
  return *this;
}

char StringBad::operator[](int n) {
  return str[n];
}

std::ostream & operator<<(std::ostream &os, const StringBad &s) {
  os << s.str;
  return os;
}

