print(["No", "Yes"][(lambda solve: (lambda n, m, t, a: (lambda xy: solve(n, m, t, a, xy))(list(tuple(map(int, input().split())) for _ in range(m))))(*map(int, input().split()), list(map(int, input().split()))))((lambda accumulate, defaultdict: (lambda n, m, t, a, xy: (lambda xy_dict: all(map((0).__lt__, accumulate((xy_dict[i + 1] - a[i] for i in range(n - 1)), initial=t))))(defaultdict(int, xy))))(__import__("itertools").accumulate, __import__("collections").defaultdict))])