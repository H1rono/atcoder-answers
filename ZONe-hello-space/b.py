barrier_num, ufo_x, ufo_y = map(int, input().split())

tan = ufo_y / ufo_x

for i in range(barrier_num):
    b_x, b_y = map(int, input().split())
    t = (ufo_y - b_y) / (ufo_x - b_x)
    tan = min(max(t, 0), tan)

print(ufo_y - tan * ufo_x)

