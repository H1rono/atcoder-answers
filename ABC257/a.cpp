#include <iostream>

int main() {
    int n, x;
    std::cin >> n >> x;
    int s = (x - 1) / n % 26;
    std::cout << (char)('A' + s) << std::endl;
}
