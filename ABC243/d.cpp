#include <iostream>
#include <cstdint>
#include <string>

using u64 = std::uint64_t;

int main() {
    u64 x, n;
    std::cin >> n >> x;
    std::string s;
    std::cin >> s;
    for (char c : s) {
        if (c == 'U') {
            x = x >> 1;
        } else if (c == 'L') {
            x = x << 1;
        } else {
            x = (x << 1) | 1;
        }
    }
    std::cout << x << std::endl;
}
