from collections import defaultdict

c1, c2, c3 = input().strip()
d = defaultdict(int)
d[c1] += 1
d[c2] += 1
d[c3] += 1

for k, v in d.items():
    if v == 1:
        print(k)
        break
else:
    print(-1)
