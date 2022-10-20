round = lambda x: int((x * 2 + 1) // 2)

def f(x: int, i: int) -> int:
    y = x / (10 ** (i + 1))
    return round(y) * (10 ** (i + 1))


def main():
    x, k = map(int, input().split())
    for i in range(k):
        x = f(x, i)
    print(x)


if __name__ == '__main__':
    main()
