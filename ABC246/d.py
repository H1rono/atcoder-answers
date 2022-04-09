"""
x = (a^2 + b^2) * (a + b)
a = b + c
x = (2 * b^2 + 2 * c * b + c^2) * (2 * b + c)
"""

n = int(input())

for curt_n_int in range(n):
    if curt_n_int ** 3 > n:
        break

x_min = None
for a in range(curt_n_int):
    for b in range(curt_n_int - a):
        x = (a * a + b * b) * (a + b)
        if x < n:
            continue
        if not x_min:
            x_min = x
        else:
            x_min = min(x_min, x)
        break

print(x_min)
