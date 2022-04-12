#include <iostream>

int main() {
    int v, a, b, c;
    std::cin >> v >> a >> b >> c;
    while (1) {
        v -= a;
        if (v < 0) {
            std::cout << 'F' << std::endl;
            break;
        }
        v -= b;
        if (v < 0) {
            std::cout << 'M' << std::endl;
            break;
        }
        v -= c;
        if (v < 0) {
            std::cout << 'T' << std::endl;
            break;
        }
    }
}