#ifndef PERSON__H__
#define PERSON__H__

#include <string>

class Person {
  std::string _name;
public: 
  Person();
  Person(const std::string name);
  ~Person();
  std::string name() const;
};

#endif
