from collections import defaultdict

n = int(input())
list_a = list(map(int, input().split()))

d = defaultdict(lambda: 0)

for a in list_a:
    d[a] += 1

max_a = max(list_a)
ans = 0

for q in range(1, max_a + 1):
    for r in range(1, int(max_a / q) + 1):
        p = q * r
        ans += d[p] * d[q] * d[r]

print(ans)
