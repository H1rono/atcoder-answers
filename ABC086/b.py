from math import sqrt


def solve(a: int, b: int) -> bool:
    c = int(str(a) + str(b))
    return c == int(sqrt(c)) ** 2


def main():
    a, b = map(int, input().split())
    if solve(a, b):
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    main()