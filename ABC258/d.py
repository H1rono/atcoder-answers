n, x = map(int, input().split())
accum_time = 0
ans = None
min_b = None


for i in range(1, n + 1):
    a, b = map(int, input().split())
    accum_time += a + b
    if ans is None:
        ans = accum_time + b * (x - i)
        min_b = b
        continue
    min_b = min(min_b, b)
    ans = min(ans, accum_time + min_b * (x - i))


print(ans)
