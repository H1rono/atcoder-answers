#include <iostream>

inline constexpr int pow2(int v) {
    return v * v;
}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    bool res = pow2(a) + pow2(b) < pow2(c);
    std::cout << (res ? "Yes" : "No") << std::endl;
}