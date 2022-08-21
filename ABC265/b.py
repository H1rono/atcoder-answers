def solve(n, m, t, a, xy) -> bool:
    consumed_time = 0
    xy_it = iter(xy)
    try:
        x, y = next(xy_it)
    except StopIteration:
        x, y = -1, -1
    for room, lost in enumerate(a, 1):
        if room == x:
            consumed_time -= y
            try:
                x, y = next(xy_it)
            except StopIteration:
                x, y = -1, -1
        consumed_time += lost
        if consumed_time >= t:
            return False
    return True


def main():
    n, m, t = map(int, input().split())
    a = list(map(int, input().split()))
    xy = [list(map(int, input().split())) for _ in range(m)]
    print(["No", "Yes"][solve(n, m, t, a, xy)])


if __name__ == "__main__":
    main()
