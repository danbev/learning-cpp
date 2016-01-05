#include <iostream>
#include "linkedlist.cpp"
#include <iostream>

LinkedIntList primefactors(int nr) {
  std::cout << "Factor " << nr << std::endl;
  LinkedIntList list;
  for (int i =2; i < nr; i++) {
    while (nr % i == 0) { 
      // nr is evenly divisable so i is a factor
      list.push(i);
      std::cout << i << " is a factor of " << nr << std::endl;
      nr = nr / i;
    }
  }
  if (nr > 1) {
    std::cout << nr << " left " << std::endl;
    list.push(nr);
  }
  return list;
}

