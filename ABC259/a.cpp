#include <iostream>

int main() {
    int n, m, x, t, d;
    std::cin >> n >> m >> x >> t >> d;
    std::cout << (
        m <= x ? t - d * (x - m) : t
    ) << std::endl;
}