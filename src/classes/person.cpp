// clang++ -std=c++11 -stdlib=libc++ person.cpp -o person
#include <iostream>
#include "person.h"
#include <string>

Person::Person() {
  _name = "unknown";
}

Person::Person(const std::string name) {
  _name = name;
}

Person::~Person() {
  std::cout << "Descructing Person[" << *this  << "]" << std::endl;
}

std::string Person::name() const { 
  return _name;
}

std::ostream & operator<<(std::ostream &os, const Person &p) {
  os << "name=" << p.name();
  return os;
}

Person operator+(const Person &p1, const Person &p2) {
  return Person(p1.name() + p2.name());
}

Person Person::operator=(const std::string &s) {
  return Person(s);
}

int main() {
  Person p ("Fletch");
  Person p2;
  Person p3 = Person("Bajja");
  Person p4 {"Four"};
  std::string name = "beve";
  Person p5 = name;
  std::cout << p << std::endl;
  std::cout << p2 << std::endl;
  std::cout << p3 << std::endl;
  std::cout << p4 << std::endl;
  std::cout << p5 << std::endl;
  return 0;
}
