#include <iostream>
#include <string>
int main() {
    int i = 10;
    int y(10);
    int x{20};
    std::cout << i + y + x << std::endl;
    return 0;
}
