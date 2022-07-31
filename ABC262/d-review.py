from functools import reduce
from operator import mul


MAX = 998244353
ln = int(input())
nums = list(map(int, input().split()))
# 二項係数 co[i][j] := _(i + j) C _i
co = []


for i in range(ln + 1):
    co.append([])
    for j in range(ln + 1):
        co[i].append(
            (co[i][j - 1] + co[i - 1][j]) % MAX
            if i * j else 1)


def search(mods, choices, choiced = 0, least_choice = 0) -> int:
    # print(mods, choices, choiced, least_choice)
    l = len(mods)
    if choiced >= l:
        ans = (
            (not (sum(i * c for i, c in enumerate(choices)) % l))
            * reduce(mul, (co[m - c][c] for m, c in zip(mods, choices)))
        ) % MAX
        # print(choices, ans)
        return ans
    s = 0
    for i in range(least_choice, l):
        if choices[i] >= mods[i]:
            continue
        nchoices = choices[:]
        nchoices[i] += 1
        s += search(mods, nchoices, choiced + 1, i) % MAX
    return s % MAX


ans = 0


for i in range(1, ln + 1):
    mods = [0] * i
    for a in nums:
        mods[a % i] += 1
    # print(i, mods)
    ans += search(mods, [0] * i)
    ans %= MAX


print(ans)
