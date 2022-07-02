n = int(input())
board = [
    list(map(int, input())) for _ in range(n)
]

max_num = 0
max_num_boxes = []

for r in range(n):
    for c in range(n):
        num = board[r][c]
        if num > max_num:
            max_num = num
            max_num_boxes = [(r, c)]
        elif num == max_num:
            max_num_boxes.append((r, c))

def begins_num(row, col):
    ans = 0
    for dr, dc in [
        (1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1)
    ]:
        s = ""
        for i in range(n):
            s += str(board[(row + i * dr) % n][(col + i * dc) % n])
        ans = max(ans, int(s))
    return ans

ans = max(begins_num(r, c) for r, c in max_num_boxes)
print(ans)
