n = int(input())
h = list(map(int, input().split()))

ans = 0
for i in range(n):
    if h[ans] < h[i]:
        ans = i

print(ans + 1)
