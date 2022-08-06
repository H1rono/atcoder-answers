#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <utility>
#include <queue>

using i64 = std::int64_t;
using p_ii64 = std::pair<i64, int>;

i64 x_sum_diff(int n, i64 l, i64 x, const std::vector<i64> & accum) {
    return x * l - accum[x];
}

i64 y_sum_diff(int n, i64 r, i64 y, const std::vector<i64> & accum) {
    return y * r - (accum[n] - accum[n - y]);
}

i64 solve(int n, i64 l, i64 r, const std::vector<i64> & a) {
    std::vector<i64> accum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        accum[i + 1] = accum[i] + a[i];
    }
    std::vector<i64>
        accum_xdiff_min(n + 1, x_sum_diff(n, l, 0, accum)),
        accum_ydiff_min(n + 1, y_sum_diff(n, r, 0, accum));
    for (int i = 0; i < n; ++i) {
        accum_xdiff_min[i + 1] = std::min(accum_xdiff_min[i], x_sum_diff(n, l, i + 1, accum));
        accum_ydiff_min[i + 1] = std::min(accum_ydiff_min[i], y_sum_diff(n, r, i + 1, accum));
    }
    i64 diff_min = 0;
    for (int i = 0; i <= n; ++i) {
        i64 x = i, y = n - i;
        diff_min = std::min(diff_min, accum_xdiff_min[x] + accum_ydiff_min[y]);
    }
    return accum[n] + diff_min;
}

int main() {
    int n;
    i64 l, r;
    std::cin >> n >> l >> r;
    std::vector<i64> a(n, 0);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    i64 ans = solve(n, l, r, a);
    std::cout << ans << std::endl;
}
