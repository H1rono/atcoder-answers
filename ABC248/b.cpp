#include <iostream>
#include <cstdint>

using u64 = std::uint64_t;

int main() {
    u64 a, b, k;
    std::cin >> a >> b >> k;
    u64 x = 0, slime_num = a;
    while (slime_num < b) {
        slime_num *= k;
        x++;
    }
    std::cout << x << std::endl;
}
