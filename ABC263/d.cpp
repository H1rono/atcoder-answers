#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <utility>

using i64 = std::int64_t;
using p_ii64 = std::pair<i64, int>;

int binary_search(p_ii64 x, const std::vector<p_ii64> & a) {
    int l = -1, r = a.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (a[m] < x) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}

void insert(p_ii64 x, std::vector<p_ii64> & a) {
    int i = binary_search(x, a);
    a.insert(a.begin() + i, x);
}

i64 x_sum_diff(int n, int l, int x, const std::vector<i64> & accum) {
    return x * l - accum[x];
}

i64 y_sum_diff(int n, int r, int y, const std::vector<i64> & accum) {
    return y * r - (accum[n] - accum[n - y]);
}

i64 sum(int n, int l, int r, int x, int y, const std::vector<i64> & accum) {
    return accum[n - y] + y * r - accum[x] + x * l;
}

int solve(int n, int l, int r, const std::vector<i64> & a) {
    // std::vector<p_ii64> sorted_a;
    std::vector<i64> accum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        accum[i + 1] = accum[i] + a[i];
        // insert(p_ii64(a[i], i), sorted_a);
    }
    // int center = sorted_a[0].second;
    p_ii64 x_cand = {x_sum_diff(n, l, 0, accum), 0};
    for (int x = 1; x <= n; ++x) {
        x_cand = std::min(x_cand, {x_sum_diff(n, l, x, accum), x});
    }
    int x = x_cand.second;
    p_ii64 y_cand = {y_sum_diff(n, r, 0, accum), 0};
    for (int y = 1; y <= n - x; ++y) {
        y_cand = std::min(y_cand, {y_sum_diff(n, r, y, accum), y});
    }
    int y = y_cand.second;
    return sum(n, l, r, x, y, accum);
}

int main() {
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<i64> a(n, 0);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    i64 ans = solve(n, l, r, a);
    std::cout << ans << std::endl;
}
