n, queries = map(int, input().split())
# aは単調増加にソート
a = [0] + sorted(map(int, input().split()))
# accum[i] := {k = 1} から i までの a[k] の和
accum = [0]
# {k = a} から {k = b} までの a[k] の和: accum[b] - accum[a - 1]

for i, v in enumerate(a):
    if not i: continue
    accum.append(accum[i - 1] + a[i])


# i := index(x) ... x <= a[i] を満たす最小の x
def index(x: int) -> int:
    ng, ok = -1, n + 1
    while ok - ng > 1:
        mid = (ok + ng) >> 1
        if a[mid] < x:
            ng = mid
        else:
            ok = mid
    return ok


for _ in range(queries):
    x = int(input())
    i = max(0, index(x) - 1)
    ans = (
        x * i - accum[i]
        + (accum[n] - accum[i]) - x * (n - i)
    )
    print(ans)
