// clang++ -std=c++11 -stdlib=libc++ person.cpp -o person
#include <iostream>
#include "person.h"

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

int main() {
  Person p ("Fletch");
  std::cout << "Person: " << p << std::endl;
  Person p2;
  std::cout << "Person2: " << p2 << std::endl;
  Person p3 = Person("Bajja");
  std::cout << "Person3: " << p3 << std::endl;
  Person p4 {"Four"};
  std::cout << "Person4: " << p4 << std::endl;
  return 0;
}
