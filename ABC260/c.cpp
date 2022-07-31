#include <iostream>
#include <cstdint>
#include <vector>
#include <array>

using u64 = std::uint64_t;

int main() {
    u64 n, x, y;
    std::cin >> n >> x >> y;
    // dp[n] := {レベルnの赤の数, レベルnの青の数}
    std::vector<std::array<u64, 2>> dp(n + 1, {0, 0});
    dp[n][0] = 1;
    for (u64 i = n; i > 1; --i) {
        // 赤い宝石を配る
        dp[i - 1][0] += dp[i][0];
        dp[i][1] += dp[i][0] * x;
        dp[i][0] = 0;
        // 青い宝石を配る
        dp[i - 1][0] += dp[i][1];
        dp[i - 1][1] += dp[i][1] * y;
        dp[i][1] = 0;
    }
    std::cout << dp[1][1] << std::endl;
}
