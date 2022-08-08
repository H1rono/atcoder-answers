def solve(w: int, h: int) -> int:
    if w == 1 or h == 1:
        return 1
    w_d2, w_m2 = divmod(w, 2)
    h_d2, h_m2 = divmod(h, 2)
    return (w_d2 + w_m2) * (h_d2 + h_m2) + w_d2 * h_d2


def main():
    w, h = map(int, input().split())
    ans = solve(w, h)
    print(ans)


if __name__ == '__main__':
    main()
