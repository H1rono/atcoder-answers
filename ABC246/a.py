def read_point():
    return tuple(map(int, input().split()))


x1, y1 = read_point()
x2, y2 = read_point()
x3, y3 = read_point()

x4 = x1 if x2 == x3 else x2 if x3 == x1 else x3
y4 = y1 if y2 == y3 else y2 if y3 == y1 else y3
print(x4, y4)