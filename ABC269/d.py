from logging import root


class UnionFind:
    def __init__(self, length: int) -> None:
        self.parents = list(range(length))
        self.sizes = [0 for _ in range(length)]

    def root(self, u: int) -> int:
        if self.parents[u] == u:
            return u
        r = self.root(self.parents[u])
        self.parents[u] = r
        return r

    def equiv(self, u: int, v: int) -> bool:
        return self.root(u) == self.root(v)

    def unite(self, u: int, v: int) -> None:
        u_root, v_root = self.root(u), self.root(v)
        if u_root == v_root:
            return
        self.parents[u_root] = v_root
        self.sizes[v_root] += self.sizes[u_root]
        self.sizes[u_root] = 0

n = int(input())
points = []
blacks = {}

for i in range(n):
    p = tuple(map(int, input().split()))
    points.append(p)
    blacks[p] = i

uf = UnionFind(n)

for i in range(n):
    x, y = points[i]
    for (dx, dy) in [(-1, -1), (-1, 0), (0, -1), (0, 1), (1, 0), (1, 1)]:
        np = (x + dx, y + dy)
        j = blacks.get(np, None)
        if j is not None:
            uf.unite(i, j)

ans = len({uf.root(i) for i in range(n)})
print(ans)
