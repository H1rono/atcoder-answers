from math import sqrt

x, y = map(int, input().split())
mag = sqrt(x * x + y * y)
print(x / mag, y / mag)