n, m = map(int, input().split())


def generate(ln: int, mi: int, ma: int) -> list:
    if ln == 1:
        return [[i] for i in range(mi, ma + 1)]
    res = []
    for i in range(mi, ma - ln + 2):
        l = generate(ln - 1, i + 1, ma)
        for j in l:
            res.append([i] + j)
    return res


def print_list(a):
    print(*a, sep=' ')


ans = generate(n, 1, m)
for i in ans:
    print_list(i)
