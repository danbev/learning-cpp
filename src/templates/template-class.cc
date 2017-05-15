#include <iostream>
#include "template-header.h"

template<typename T>
TemplateClass<T>::TemplateClass(T type) : type_(type) {}

template<typename T>
T TemplateClass<T>::get() {
  return type_;
}

template<typename T>
void TemplateClass<T>::print() {
  std::cout << "type = " <<  type_ << std::endl;
}

template<typename T>
void TemplateClass<T>::usage() {
  // this is a point of usage in which case the complier will need 
  // a template instance so it will generate one for the type of T
  print();
}

// that is all well but we still need to have specific 
// initialisations for members (not static class functions)
//template class TemplateClass<int>;

// Alternatively you can explicitly declare all the functions:
template TemplateClass<int>::TemplateClass(int);
template int TemplateClass<int>::get();
//template void TemplateClass<int>::print();
template void TemplateClass<int>::usage();


template<typename T>
void TemplateClass<T>::staticPrint(T t) {
  std::cout << "type = " <<  t << std::endl;
};

// Explicit instantiation for a specialisation of the 
// static template with type int.
//
// If we comment this out things will still compile fine
// but the compiler will not have instanciated an instance for the
// template. Since the usage of the template is in a separate file
// and compiled separately so implicit instanciation will not work.
//
// The usage in our test will just have a symbol created which 
// is up to the linker to resolve later.
//
// These leads to a problem for the linker when it tries to 
// link another object file which refers to a concrete call.
// In this case it is our test file:
// Undefined symbols for architecture x86_64:
//   "TemplateClass<int>::staticPrint(int)", referenced from:
//      TemplateClass_usage_Test::TestBody() in template_class_test-template_class_test.o
// ld: symbol(s) not found for architecture x86_64
//
template void TemplateClass<int>::staticPrint(int);
