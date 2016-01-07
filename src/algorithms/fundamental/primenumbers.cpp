#include <iostream>
#include "../datastructures/linkedlist.cpp"
#include <iostream>

LinkedList primefactors(int nr) {
  std::cout << "Factor " << nr << std::endl;
  LinkedList list;
  for (int i =2; i < nr; i++) {
    while (nr % i == 0) { 
      // nr is evenly divisable so i is a factor
      list.addFront(i);
      std::cout << i << " is a factor of " << nr << std::endl;
      nr = nr / i;
    }
  }
  if (nr > 1) {
    std::cout << nr << " left " << std::endl;
    list.addFront(nr);
  }
  return list;
}

