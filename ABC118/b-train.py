n, m = map(int, input().split())
likes = [[] for _ in range(m)]

for i in range(n):
    k, *a = map(int, input().split())
    for j in range(k):
        likes[a[j] - 1].append(i)

ans = sum(map(lambda l: len(l) == n, likes))
print(ans)
