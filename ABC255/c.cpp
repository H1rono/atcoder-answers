#include <iostream>
#include <cstdint>
#include <algorithm>

using i64 = std::int64_t;

int main() {
    i64 x, a, d, n;
    std::cin >> x >> a >> d >> n;
    i64 left = 0, right = n + 1;
    bool r_upper = d > 0;
    auto s = [&](i64 k) -> i64 {
        return k < 1 ? a : k > n ? a + d * (n - 1) : a + d * (k - 1);
    };
    auto cond = [&](i64 v) -> bool {
        return r_upper ? v >= x : v <= x;
    };
    while (right - left > 1) {
        i64 mid = ((right - left) >> 1) + left;
        if (cond(s(mid))) {
            right = mid;
        } else {
            left = mid;
        }
    }
    i64 ld = std::abs(s(left) - x);
    i64 rd = std::abs(s(right) - x);
    i64 ans = ld < rd ? ld : rd;
    std::cout << ans << std::endl;
}