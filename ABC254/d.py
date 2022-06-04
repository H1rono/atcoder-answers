from math import log, floor, sqrt


n = int(input())
squares = [ i * i for i in range(1, n + 1) ]

def is_square(x):
    ng, ok = -1, n
    while ok - ng > 0:
        mid = (ok + ng) // 2
        if squares[mid] < x:
            ng = mid
        else:
            ok = mid
    return squares[ok] == x

ans = 0

for i in range(1, n + 1):
    for j in range(1, i + 1):
        mul = i * j
        if floor(sqrt(mul)) ** 2 == mul:
            ans += 1 + (i != j)

print(ans)
