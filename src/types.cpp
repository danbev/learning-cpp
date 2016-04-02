#include <iostream>
#include <string>
int main() {
    int i = 10;
    auto y(10);
    decltype(i) x{20};
    std::cout << i + y + x << std::endl;
    return 0;
}
