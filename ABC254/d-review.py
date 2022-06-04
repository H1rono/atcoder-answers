# https://atcoder.jp/contests/abc254/editorial/4079

n = int(input())

# 線形篩
# reast prime factor: 最小素因数
lpf = [i if i < 2 else None for i in range(n + 1)]
isprime = [i >= 2 for i in range(n + 1)]
primes = []

for i in range(2, n + 1):
    if not isprime[i]:
        continue
    primes.append(i)
    lpf[i] = i
    for j in range(2, n // i + 1):
        mul = i * j
        isprime[mul] = False
        if lpf[mul] is None:
            lpf[mul] = i

# dp[i]: iの素因数のうち、指数部が奇数であるもの（の 1 乗）の積
dp = [1 for i in range(n + 1)]

for i in range(2, n + 1):
    j = i // lpf[i]
    if not dp[j] % lpf[i]:
        dp[i] = dp[j] // lpf[i]
    else:
        dp[i] = dp[j] * lpf[i]

ans = 0

for i in range(1, n + 1):
    j_min = dp[i]
    for d in range(1, n + 1):
        if j_min * d * d > n:
            break
        ans += 1

print(ans)
