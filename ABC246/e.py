n = int(input())
ax, ay = tuple(map(lambda p: int(p) - 1, input().split()))
bx, by = tuple(map(lambda p: int(p) - 1, input().split()))
board  = tuple(tuple(map("#".__ne__, input())) for _ in range(n))

INF = 1 << 30

d_poss = ((1, 1), (1, -1), (-1, 1), (-1, -1))
costs  = [[INF] * n for _ in range(n)]
search_entries = []


def can_put_piece(x, y):
    return 0 <= x < n and 0 <= y < n and board[x][y]


def push(x, y, cost):
    if not can_put_piece(x, y):
        return False
    c = costs[x][y]
    if c <= cost:
        return False
    costs[x][y] = min(cost, c)
    search_entries.append((x, y))
    return True

push(ax, ay, 0)

while search_entries:
    x, y = search_entries.pop()
    cost = costs[x][y] + 1
    for dx, dy in d_poss:
        x_, y_ = x + dx, y + dy
        while push(x_, y_, cost):
            x_ += dx
            y_ += dy

c = costs[bx][by]
ans = -1 if c == INF else c
print(ans)

