a, b, c, d, e, f = map(int, input().split())

mod = 998244353

ans = (a * b * c) % mod
ans -= (d * e * f) % mod
print(ans % mod)
