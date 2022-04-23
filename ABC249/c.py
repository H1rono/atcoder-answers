from collections import defaultdict

n, k = map(int, input().split())
ss = [input() for _ in range(n)]

get_indices = lambda num: [i for i in range(num.bit_length()) if (num >> i) & 1]

ans = 0

for i in range(1 << n):
    indices = get_indices(i)
    d = defaultdict(lambda: 0)
    for i in indices:
        s = ss[i]
        for c in s:
            d[c] += 1
    cnt = 0
    for c in 'abcdefghijklmnopqrstuvwxyz':
        cnt += d[c] == k
    ans = max(ans, cnt)

print(ans)
