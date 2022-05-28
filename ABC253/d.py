n, a, b = map(int, input().split())


def floar_sum(v: int) -> int:
    f = int(n / v)
    return v * f * (f + 1) // 2


sn = n * (n + 1) // 2
sa = floar_sum(a)
sb = floar_sum(b)
sab = floar_sum(a * b)
ans = sn - sa - sb + sab
print(ans)
