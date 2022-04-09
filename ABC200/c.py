n = int(input())
seq = [(0, 0) for _ in range(100)]
it = map(int, input().split())
for a in it:
    v, i = divmod(a, 100)
    f, s = seq[i]
    if v & 1:
        s += 1
    else:
        f += 1
    seq[i] = (f, s)

ans = 0
for (first, second) in seq:
    ans += (
        ((first * (first - 1)) >> 1)
        + ((second * (second - 1)) >> 1)
    )

print(ans)