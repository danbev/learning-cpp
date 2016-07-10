#include <iostream>
#include <string>

#define DANBEV_PUBLIC __attribute__ ((visibility ("default")))


class Visibility {
  public:
    DANBEV_PUBLIC std::string doitPublic() {
      std::cout << "public odit..." << std::endl;
      return "public"; 
    }
    std::string doitPrivate() {
      std::cout << "private odit..." << std::endl;
      return "private"; 
    }
};
