n = int(input())

vals = map(int, input().split())
ans, sum1, sum2 = 0, 0, 0
for i, v in enumerate(vals):
    sq_v = v * v
    ans += sq_v * i
    ans -= 2 * v * sum1
    ans += sum2
    sum1 += v
    sum2 += sq_v

print(ans)

