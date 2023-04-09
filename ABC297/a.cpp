#include <cstdint>
#include <iostream>
#include <vector>

using usize = std::size_t;
using u32 = std::uint32_t;
using i32 = std::int32_t;

int main() {
    std::size_t n;
    u32 d;
    std::cin >> n >> d;
    std::vector<u32> ts(n);
    for (u32 &t : ts) {
        std::cin >> t;
    }
    i32 ans = -1;
    for (usize i = 0; i < n - 1; ++i) {
        if (ts[i + 1] - ts[i] <= d) {
            ans = ts[i + 1];
            break;
        }
    }
    std::cout << ans << std::endl;
}
