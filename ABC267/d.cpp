#include <iostream>
#include <vector>
#include <cstdint>

using i64 = int64_t;

i64 solve(int n, int m, const std::vector<i64>& a) {
    constexpr i64 MIN = -1e16;
    // dp[i][j] : i + 1個の数を使って得られる部分列で最後の要素がa[j]の時の最大値
    std::vector<std::vector<i64>> dp(m, std::vector<i64>(n, MIN));
    for (int i = 0; i < n; ++i) {
        dp[0][i] = a[i];
    }
    for (int i = 1; i < m; ++i) {
        int range_min = i - 1;
        int range_max = n - m + i + 1;
        for (int j = range_min; j < range_max - 1; ++j) {
            for (int k = j + 1; k < range_max; ++k) {
                dp[i][k] = std::max(dp[i][k], dp[i - 1][j] + (i + 1) * a[k]);
            }
        }
    }
    const std::vector<i64>& last_dp = dp[m - 1];
    int range_min = m - 1;
    int range_max = n;
    i64 max_sum = last_dp[range_min];
    for (int i = range_min; i < range_max; ++i) {
        max_sum = std::max(max_sum, last_dp[i]);
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
