n, k = map(int, input().split())
ans = str(n)
for _ in range(k):
    if len(ans) > 2 and ans[-2:] == "00" and int(ans[-3]) & 1 == 0:
        ans = str(int(ans[:-2]) >> 1)
    else:
        ans += "200"

print(ans)