#include <iostream>
#include <sys/mman.h>
#include <cstddef>
#include <unistd.h>
#include <atomic>
#include <climits>
 
int main(void) {
  size_t pagesize = static_cast<size_t>(sysconf(_SC_PAGESIZE));
  std::cout << "_SC_PAGESIZE: " << pagesize << " bytes\n";
 
  void* map_map = mmap(NULL, // let the kernel choose the address
                        pagesize, // length of the mapping
                        PROT_READ | PROT_WRITE,
                        MAP_ANONYMOUS | MAP_PRIVATE,
                        -1, // since this is an anonymous mapping fd is ignored
                        0); // likewise the offset should be zero in this case.

  if (map_map == MAP_FAILED) {
    std::cout << "Could not mmap" << '\n';
    return 1;
  }
  uintptr_t top = reinterpret_cast<uintptr_t>(map_map);

  std::cout << "map_map: " << map_map <<  '\n';
  std::cout << "top: " << std::hex << top <<  '\n';

  // Add a int to the top of the memory map
  int* id = reinterpret_cast<int*>(top);
  __atomic_store_n(id, 4, __ATOMIC_RELAXED);

  // update top to account of the int at the top of the memory map
  top += sizeof(id);

  int id_value = __atomic_load_n(id, __ATOMIC_RELAXED);
  std::cout << "id: " << id_value << '\n';
  std::cout << "top: " << top << '\n';
 
  // Add another int to position that top points to
  int* age = reinterpret_cast<int*>(top);
  __atomic_store_n(age, 3, __ATOMIC_RELAXED);
  
  // update top to account of the int at the top of the memory map
  top += sizeof(age);
  std::cout << "top: " << top << '\n';
  int age_value = __atomic_load_n(age, __ATOMIC_RELAXED);
  std::cout << "age: " << age_value << '\n';
 
  int unmap_result = munmap(map_map, pagesize);
  if (unmap_result != 0 ) {
    std::cout << "Could not munmap" << '\n';
    return 1;
  }
  return 0;
}
