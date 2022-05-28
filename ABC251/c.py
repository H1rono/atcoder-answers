n = int(input())
sub_strs = set()
best_t, best_i = 0, 0

for i in range(n):
    s, t = input().split()
    t = int(t)
    if s in sub_strs:
        continue
    sub_strs.add(s)
    if best_t < t:
        best_t = t
        best_i = i + 1

print(best_i)