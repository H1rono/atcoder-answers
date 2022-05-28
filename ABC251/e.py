n = int(input())
ptn_a, ptn_b = 0, 0
a_s = map(int, input().split())

for i, a in enumerate(a_s):
    if i & 1:
        ptn_b += a
    else:
        ptn_a += a

print(min(ptn_a, ptn_b))