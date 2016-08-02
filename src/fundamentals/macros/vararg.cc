#include <string>
#include <iostream>

#define ASSIGN_OR_RETURN_UNWRAP(ptr, obj, ...)                               \
 do {                                                                        \
   *ptr = nullptr ;                                                          \
   if (*ptr == nullptr)                                                      \
     return __VA_ARGS__;                                                     \
} while (0)

class VarArgExample {
 public:
   VarArgExample(std::string name);

   std::string name() const { return name_; };
   int useMacro() const;

  private:
    std::string name_;

};

VarArgExample::VarArgExample(std::string name) : name_(name) {}

int VarArgExample::useMacro() const {
  int* ptr = nullptr;
  ASSIGN_OR_RETURN_UNWRAP(&ptr, NULL, 10);
  // Just curious to what happens if no varargs are provided:
  //ASSIGN_OR_RETURN_UNWRAP(&ptr, NULL);
}

