n, w = map(int, input().split())
a = list(map(int, input().split()))
g = [False for _ in range(w + 1)]

def f(v):
    if v <= w:
        g[v] = True

for i in range(n):
    f(a[i])
    for j in range(i + 1, n):
        f(a[i] + a[j])
        for k in range(j + 1, n):
            f(a[i] + a[j] + a[k])

ans = sum(g)

print(ans)
