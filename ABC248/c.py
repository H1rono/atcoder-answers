N, M, K = map(int, input().split())

dp = [[0] * (N * M + 10) for i in range(N + 1)]
for i in range(1, M + 1):
    dp[0][i] = 1

for i in range(2, N + 1):
    i_ = i - 1
    for j in range(i_, M * i_):
        for k in range(1, M + 1):
            dp[i_][j + k] += dp[i - 2][j]

ans = 0
for i in range(N, K + 1):
    ans += dp[N - 1][i]
print(ans % 998244353)

