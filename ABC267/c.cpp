#include <iostream>
#include <vector>
#include <cstdint>

using i64 = int64_t;

i64 solve(int n, int m, const std::vector<i64>& a) {
    std::vector<i64> accum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        accum[i + 1] = accum[i] + a[i];
    }
    i64 current_sum = 0;
    for (int i = 0; i < m; ++i) {
        current_sum += a[i] * (i + 1);
    }
    i64 max_sum = current_sum;
    for (int i = m; i < n; ++i) {
        current_sum += a[i] * m - accum[i] + accum[i - m];
        max_sum = std::max(max_sum, current_sum);
    }
    return max_sum;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::cout << solve(n, m, a) << std::endl;
}
