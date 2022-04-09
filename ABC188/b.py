n = int(input())
a_vec = map(int, input().split())
b_vec = map(int, input().split())
d_mul = 0
for a, b in zip(a_vec, b_vec):
    d_mul += a*b
print("Yes" if not d_mul else "No")