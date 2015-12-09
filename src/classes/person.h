#ifndef PERSON__H__
#define PERSON__H__

#include <string>
#include <iostream>

class Person {
  std::string _name;
public: 
  Person();
  Person(const std::string name);
  ~Person();
  std::string name() const;
  friend std::ostream & operator<<(std::ostream &os, const Person &p);
};

#endif
