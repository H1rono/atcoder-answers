#include <algorithm>
#include <cstdint>
#include <iostream>

using u64 = std::uint64_t;

int main() {
    u64 a, b, c;
    std::cin >> a >> b >> c;
    u64 ans = a & b & c & 1 ? std::min(a * b, std::min(b * c, c * a)) : 0;
    std::cout << ans << std::endl;
}
