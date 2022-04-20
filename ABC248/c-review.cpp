/*
解法: DP(動的計画法)
# 定義
行列dp[i][j] := 数列の初項から第i項まで決めた際に、総和がjであるような数列の決め方
i = 1 .. N, j = 1 .. K であるため、NK個のセルを埋めればよい
# 初期値
dp[0][0] = 1で、他は0
# dpの遷移
iの昇順に計算していく。j = 1 .. K - 1, k = 1 .. Mについて、
j + k <= Kならば、dp[i + 1][j + k] += dp[i][j]
*/

#include <iostream>
#include <cstdint>
#include <vector>

using u64 = std::uint64_t;
using std::vector;

int main() {
    int N, M, K;
    std::cin >> N >> M >> K;
    // dp[i-1][j-1] := sum(A[..i]) == j となるようなA[..i]の数
    // i = 1 .. N, j = 1 .. N * M
    vector<vector<u64> *> dp{};
    // 初期値設定
    for (int i = 1; i <= N; ++i) {
        dp.push_back(new vector<u64>(N * M));
    }
    auto at = [&dp](int i, int j) -> u64 & {
        return dp[i - 1]->at(j - 1);
    };
    for (int j = 1; j <= M; ++j) {
        // sum(A[1]) == A[1]であり、A[1] = 1 .. M (すべて1通りずつ)
        dp[0]->at(j - 1) = 1;
    }
    // 行列を埋めていく
    for (int i = 2; i <= N; ++i)
    for (int j_ = i - 1; j_ <= (i - 1) * M; ++j_) // dp[i][j] != 0 であるのは i <= j <= i * M の時
    for (int a_i = 1; a_i <= M; ++a_i) {
        int j = j_ + a_i;
        u64 & target = at(i, j);
        target += at(i - 1, j_);
        target %= 998244353; // オーバーフロー対策
    }
    u64 ans = 0;
    for (int j = N; j <= K; ++j) {
        ans += dp[N - 1]->at(j - 1);
    }
    ans %= 998244353;
    std::cout << ans << std::endl;
}
