#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

using std::size_t;
using u64 = std::uint64_t;

int main() {
    size_t n, m;
    std::cin >> n >> m;
    std::vector<std::pair<u64, size_t>> drinks;
    for (size_t i = 0; i < n; ++i) {
        u64 a;
        size_t b;
        std::cin >> a >> b;
        drinks.emplace_back(a, b);
    }
    std::sort(drinks.begin(), drinks.end());
    u64 ans = 0;
    for (auto [price, count] : drinks) {
        size_t cnt = std::min(m, count);
        m -= cnt;
        ans += price * cnt;
        if (m <= 0) {
            break;
        }
    }
    std::cout << ans << std::endl;
}
