#include <string>
#include <iostream>

#define STRING_SYMBOL_PROPERTIES(V)                                           \
  V(test_private_symbol, "test:private_symbol")                               \
  V(test_private_symbol2, "test:private_symbol2")                             \

class MacroExample {
 public:
   MacroExample();

   std::string getName() const;

#define VS(PropertyName, StringValue) V(std::string, PropertyName, StringValue)
#define V(TypeName, PropertyName, StringValue)                                \
  inline TypeName PropertyName() const;
  STRING_SYMBOL_PROPERTIES(VS)
#undef V
#undef VS

 public:
 // The fields would normally be private
#define VS(PropertyName, StringValue) V(std::string, PropertyName, StringValue)
#define V(TypeName, PropertyName, StringValue)                                \
  TypeName PropertyName ## _;
  STRING_SYMBOL_PROPERTIES(VS)
#undef V
#undef VS

  private:
    std::string name_;

};

#define VS(PropertyName, StringValue) V(std::string, PropertyName, StringValue)
#define V(TypeName, PropertyName, StringValue)                                \
inline TypeName MacroExample::PropertyName() const {                          \
   return PropertyName ## _;    \
 }
 STRING_SYMBOL_PROPERTIES(VS)
#undef V
#undef VS

MacroExample::MacroExample() :
#define V(PropertyName, StringValue)                                          \
  PropertyName ## _ (StringValue),                                           
  STRING_SYMBOL_PROPERTIES(V) 
#undef V
name_("testing")
{
  std::cout << "MacroExample Constructor...." << std::endl;
}
