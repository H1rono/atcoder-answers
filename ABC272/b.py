def judge(n, counts):
    it = ((i, j) for i in range(n) for j in range(i + 1, n))
    for i, j in it:
        if not counts[i][j]:
            return False
    return True


def main():
    n, m = map(int, input().split())
    counts = [[False] * n for _ in range(n)]
    for _ in range(m):
        k, *xs = map(int, input().split())
        it = ((i, j) for i in range(k) for j in range(i + 1, k))
        for i, j in it:
            x1 = xs[i] - 1
            x2 = xs[j] - 1
            counts[x1][x2] = True
            counts[x2][x1] = True
    if judge(n, counts):
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()
