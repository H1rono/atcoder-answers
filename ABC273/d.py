def main():
    h, w, r0, c0 = map(int, input().split())
    n = int(input())
    walls = [tuple(map(int, input().split())) for _ in range(n)]
    iswall = [[False] * w for _ in range(h)]
    for r, c in walls:
        iswall[r - 1][c - 1] = True
    r, c = r0 - 1, c0 - 1
    q = int(input())
    for _ in range(q):
        d, l = input().split()
        l = int(l)
        dr, dc = 0, 0
        if d == 'U':
            dr = -1
        elif d == 'D':
            dr = 1
        elif d == 'L':
            dc = -1
        elif d == 'R':
            dc = 1
        for _ in range(l):
            r += dr
            c += dc
            if 0 <= r < h and 0 <= c < w and not iswall[r][c]:
                continue
            r -= dr
            c -= dc
            break
        print(r + 1, c + 1)


if __name__ == '__main__':
    main()
