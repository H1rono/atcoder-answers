from itertools import permutations


def solve(n, m, s, t):
    it = permutations(range(n))
    for rep in it:
        l = [s[i] for i in rep]
        x_orders = [tuple([1] * (n - 1))]
        seen = set()
        # bfs
        while x_orders:
            x_order = x_orders.pop()
            if x_order in seen:
                continue
            seen.add(x_order)
            x = ""
            for i in range(n):
                x += l[i]
                if i < n - 1:
                    x += '_' * x_order[i]
            lx = len(x)
            if lx > 16: continue
            if 3 <= lx and x not in t:
                return x
            for i in range(n - 1):
                x_orders.append(tuple([
                    x_order[j] + (i == j) for j in range(n - 1)
                ]))
    return "-1"


def main():
    n, m = map(int, input().split())
    s = [input() for _ in range(n)]
    t = {input() for _ in range(m)}
    print(solve(n, m, s, t))


if __name__ == "__main__":
    main()
