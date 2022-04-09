#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;
    if (x == y) {
        std::cout << x;
    } else {
        std::cout << (3 - x - y);
    }
    std::cout << std::endl;
}