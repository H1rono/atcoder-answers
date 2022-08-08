def solve(n: int) -> str:
    ng, ok = 0, n
    while ok - ng > 1:
        mid = (ok + ng) // 2
        if int(mid * 1.08) < n:
            ng = mid
        else:
            ok = mid
    return str(ok) if int(ok * 1.08) == n else ":("


def main():
    n = int(input())
    ans = solve(n)
    print(ans)


if __name__ == '__main__':
    main()
