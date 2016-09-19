#include "util.h"
#include <iostream>

/*
 * field The pointer-to-member (the offset of the field within the class object)
 * inner The pointer to the source object.
 */
template <typename Inner, typename Outer>
ContainerOfHelper<Inner, Outer>::ContainerOfHelper(Inner Outer::*field,
                                                   Inner* pointer)
    : pointer_(reinterpret_cast<Outer*>(
               reinterpret_cast<uintptr_t>(pointer) -
               reinterpret_cast<uintptr_t>(&(static_cast<Outer*>(0)->*field)))) {
      // A pointer is only a memory address but the type of the object determines how a 
      // pointer can be used, like using a member it needs to know the offsets of those members.
      //
      // Here we are taking the offset of the pointer-to-member (field) and subtracting
      // that from the pointer argument. Later, when we want to dereference this memory
      // using a pointer of type Outer this will be:
      // pointer-to-Outer + offset. This will give the same memory location as the passed
      // int pointer.
      //
      // Remember that that the difference between pointers lies in the type of object
      // being addressed.
      //
      // A pointer-to-member gives the offset within the class object.
      // Using the address of operator on a data member bound to an actual class object
      // yields the member's actual address in memory.
      //
      // A cast does normally not alter the actuall address but instead the interpretation
      // and composition of the memory being addressed. reinterpret_cast does not compile
      // to any CPU instructions, it merly instructs the compiler to treat the sequence of
      // bits (the object representation) as if it had the new type.
      //
      // The static_cast<Outer*>(0) will cast to a nullptr to Outer. Note that we are
      // talking about a pointer to type Outer so the compiler knows the size of the
      // object pointed to. Another example would be doing:
      // int* n = static_cast<int*>(0);
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
