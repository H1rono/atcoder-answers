def main():
    N = list(map(int, input()))
    l = len(N)
    s = sum(N)
    if s < 3:
        print(-1)
        return
    s %= 3
    if s == 0:
        print(0)
        return
    N = list(filter(None, map(lambda k : k % 3, N)))
    d = [N.count(i) for i in range(3)]
    if s == 1:
        if d[1] > 0 and l > 1:
            print(1)
        elif d[2] > 1 and l > 2:
            print(2)
        else:
            print(-1)
        return
    # s == 2
    if d[2] > 0 and l > 1:
        print(1)
    elif d[1] > 1 and l > 2:
        print(2)
    else:
        print(-1)

main()