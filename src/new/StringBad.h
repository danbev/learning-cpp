#include <iostream>
#ifndef STRINGBAD_H
#define STRINGBAD_H

class StringBad {
  private:
    char *str;
    int len;
    static int nrStrings;
  public:
    StringBad(const char *s);
    StringBad();
    StringBad(const StringBad &); // Copy Constructor
    ~StringBad();
    friend std::ostream & operator<<(std::ostream &os, const StringBad &sd); 
    StringBad & operator=(const StringBad &);
    char operator[](int n);
    StringBad & operator+(const StringBad &sb);
    static int nrOfStrings() { return nrStrings; };
};
#endif
