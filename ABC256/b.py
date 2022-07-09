n = int(input())
a = list(map(int, input().split()))

ans = n
accum = 0

for i in range(0, n):
    accum += a[n-i-1]
    if accum >= 4:
        break
    ans -= 1

print(ans)
