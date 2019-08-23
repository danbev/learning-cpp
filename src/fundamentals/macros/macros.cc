#include <string>
#include <iostream>

#define STRING_SYMBOL_PROPERTIES(V)                                           \
  V(test_private_symbol, "test:private_symbol")                               \
  V(test_private_symbol2, "test:private_symbol2")                             \

class MacroExample {
 public:
   MacroExample();

   std::string getName() const;

#define VS(PropertyName, StringValue) V(std::string, PropertyName)
#define V(TypeName, PropertyName)                                \
  inline TypeName PropertyName() const;
  STRING_SYMBOL_PROPERTIES(VS)
#undef V
#undef VS

 public:
 // The fields would normally be private
#define VS(PropertyName, StringValue) V(std::string, PropertyName)
#define V(TypeName, PropertyName)                                \
  TypeName PropertyName ## _;
  STRING_SYMBOL_PROPERTIES(VS)
#undef V
#undef VS

  private:
    std::string name_;

};

#define VS(PropertyName, StringValue) V(std::string, PropertyName)
#define V(TypeName, PropertyName)                                \
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

typedef enum {
  napi_ok
} napi_status;

/*
#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)

#define NAPI_STATUS_TO_STRING(status)                                    \
 STRINGIFY(status)

char* napi_status_to_string(napi_status status) {
  switch (status) {
    case napi_ok: 
      return NAPI_STATUS_TO_STRING(napi_ok);
  }
}
*/

#define FOREACH_STATUS(STATUS) \
        STATUS(napi_ok)        \

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

/*
enum STATUS_ENUM {
    FOREACH_STATUS(GENERATE_ENUM)
};
*/

static const char* STATUS_STRING[] = {
    FOREACH_STATUS(GENERATE_STRING)
};

static const char* something(napi_status status) {
  return STATUS_STRING[status];
}

