def solve(n, l, r, a):
    accum = [0] * (n + 1)
    x_sumdiff_min = [0] * (n + 1)
    y_sumdiff_min = [0] * (n + 1)
    x_sumdiff, y_sumdiff = 0, 0
    for i in range(1, n + 1):
        accum[i] = accum[i - 1] + a[i - 1]
        x_sumdiff += l - a[i - 1]
        y_sumdiff += r - a[n - i]
        x_sumdiff_min[i] = min(x_sumdiff, x_sumdiff_min[i - 1])
        y_sumdiff_min[i] = min(y_sumdiff, y_sumdiff_min[i - 1])
    diff_min = 0
    for i in range(n + 1):
        diff_min = min(diff_min, x_sumdiff_min[i] + y_sumdiff_min[n - i])
    return accum[n] + diff_min


def main():
    n, l, r = map(int, input().split())
    a = list(map(int, input().split()))
    ans = solve(n, l, r, a)
    print(ans)


if __name__ == '__main__':
    main()