#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    int max = 2 * a + 100;
    std::cout << (max - b) << std::endl;
}