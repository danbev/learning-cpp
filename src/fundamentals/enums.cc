#include <iostream>

enum numbers { one, two, three };
enum class numbers2 { one, two, three };

template<typename T>
std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e)
{
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

int main(int argc, char** argv) {

  std::cout << one << '\n';
  std::cout << two << '\n';

  std::cout << numbers2::two << '\n';

  numbers n = one;

  return 0;
}
