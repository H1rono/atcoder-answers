from collections import defaultdict

d = defaultdict(int)

ln = int(input())
n_it = map(int, input().split())

ans = 0
for i, n in enumerate(n_it):
    ans += i - d[n]
    d[n] += 1

print(ans)

