#include "util.h"
#include <iostream>

template <typename Inner, typename Outer>
ContainerOfHelper<Inner, Outer>::ContainerOfHelper(Inner Outer::*field,
                                                   Inner* pointer)
    : pointer_(reinterpret_cast<Outer*>(
               reinterpret_cast<uintptr_t>(pointer) -
               reinterpret_cast<uintptr_t>(&(static_cast<Outer*>(0)->*field)))) {

      // the result of pointer subtraction is the number of objects between two memory locations
      // So we are taking the pointer which in our case is a pointer to type Inner and want to 
      // figure out the where in the Outer type the field exists and set the pointer to it. 
      std::cout << "pointer: " << reinterpret_cast<uintptr_t>(pointer) << std::endl;
      std::cout << "field: " << &(static_cast<Outer*>(0)->*field) << std::endl;
      std::cout << "pointer_: " << pointer_ << std::endl;
      // later when the Out* is used the the pointer will be casted to a pointer of type of Outer.
    }

template <typename Inner, typename Outer>
template <typename TypeName>
ContainerOfHelper<Inner, Outer>::operator TypeName*() const {
  std::cout << "* operator" << std::endl;
  return static_cast<TypeName*>(pointer_);
}

template <typename Inner, typename Outer>
inline ContainerOfHelper<Inner, Outer> ContainerOf(Inner Outer::*field,
                                                   Inner* pointer) {
    return ContainerOfHelper<Inner, Outer>(field, pointer);
}
