n, a, x, y = map(int, input().split())
ans = x * min(n, a) + y * max(0, n - a)
print(ans)