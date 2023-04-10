#include <cstdint>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using usize = std::size_t;
using u64 = std::uint64_t;

int main() {
    usize n, k;
    std::cin >> n >> k;
    std::vector<u64> prices(n);
    for (usize i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }
    std::priority_queue<u64, std::vector<u64>, std::greater<u64>> q{};
    std::unordered_set<u64> pushed{0};
    q.push(0);
    u64 ans = 0;
    for (usize count = 0; count <= k; ++count) {
        const u64 p = q.top();
        q.pop();
        ans = p;
        for (usize i = 0; i < n; ++i) {
            const u64 p_ = p + prices[i];
            if (pushed.count(p_) == 0) {
                q.push(p_);
                pushed.insert(p_);
            }
        }
    }
    std::cout << ans << std::endl;
}
