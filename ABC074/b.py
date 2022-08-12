def solve(n, k, xs) -> int:
    ans = 0
    for i in range(n):
        ans += 2 * min(xs[i], abs(k - xs[i]))
    return ans


def main():
    n = int(input())
    k = int(input())
    xs = list(map(int, input().split()))
    print(solve(n, k, xs))


if __name__ == '__main__':
    main()
