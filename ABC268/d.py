from itertools import permutations
from collections import deque


def solve(n, m, s, t):
    it = permutations(range(n))
    for rep in it:
        l = [s[i] for i in rep]
        x_orders = deque([[1] * (n - 1)])
        # dfs
        while x_orders:
            x_order = x_orders.pop()
            x = ""
            for i in range(n):
                x += l[i]
                if i < n - 1:
                    x += '_' * x_order[i]
            if x not in t:
                return x
            if len(x) == 16:
                continue
            for i in range(n - 1):
                x_order[i] += 1
                x_orders.append(x_order[:])
                x_order[i] -= 1
        return "-1"


def main():
    n, m = map(int, input().split())
    s = [input() for _ in range(n)]
    t = {input() for _ in range(m)}
    print(solve(n, m, s, t))


if __name__ == "__main__":
    main()
