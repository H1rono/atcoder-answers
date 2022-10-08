from collections import deque

class Point:
    def __init__(self, x: int, y: int) -> None:
        self.x = x
        self.y = y

    def __add__(self, __o: object) -> object:
        return Point(self.x + __o.x, self.y + __o.y)

    def __sub__(self, __o: object) -> object:
        return Point(self.x - __o.x, self.y - __o.y)

    def __eq__(self, __o: object) -> bool:
        return self.x == __o.x and self.y == __o.y

    def __ne__(self, __o: object) -> bool:
        return self.x != __o.x or self.y != __o.y

    def mag_sq(self) -> int:
        return self.x ** 2 + self.y ** 2

    def dist_sq(self, other) -> int:
        dx = self.x - other.x
        dy = self.y - other.y
        return dx ** 2 + dy ** 2

    def origin_symmetry(self):
        return Point(-self.x, -self.y)

    def x_symmetry(self):
        return Point(-self.x, self.y)

    def y_symmetry(self):
        return Point(self.x, -self.y)


def main():
    n, m = map(int, input().split())
    mag_m_points = []
    def reg_point(p: Point):
        mag_m_points.append(p)
        if p.x != p.y:
            mag_m_points.append(Point(p.y, p.x))
    it = (Point(x, y) for x in range(n) for y in range(x, n))
    for p in it:
        if p.mag_sq() != m:
            continue
        reg_point(p)
        reg_point(p.x_symmetry())
        reg_point(p.y_symmetry())
        reg_point(p.origin_symmetry())
    dists = [[-1] * n for _ in range(n)]
    dists[0][0] = 0
    que = deque([Point(0, 0)])
    while que:
        p = que.popleft()
        dist = dists[p.x][p.y]
        ndist = dist + 1
        for dp in mag_m_points:
            np = p + dp
            if 0 <= np.x < n and 0 <= np.y < n and dists[np.x][np.y] < 0:
                dists[np.x][np.y] = ndist
                que.append(np)
    for row in dists:
        print(*row)


if __name__ == "__main__":
    main()

