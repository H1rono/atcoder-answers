a_deg, b_deg = map(int, input().split())
a_coefficients = list(map(int, input().split()))
b_coefficients = []
c_co = list(map(int, input().split()))

for a_min_i, a in enumerate(a_coefficients):
    if a != 0:
        break

for i in range(a_min_i, b_deg + 1):
    b_i = c_co[i + a_min_i] // a_coefficients[a_min_i]
    b_coefficients.append(b_i)
    for j in range(1, a_deg + 1):
        c_co[i + j] -= a_coefficients[j] * b_i

print(*b_coefficients)
