s = input().strip()
lefts = []
v = 0
lefts.append(v)

for c in s:
    if c == '<':
        v += 1
    else:
        v = 0
    lefts.append(v)

rights = []
v = 0
rights.append(v)

for c in reversed(s):
    if c == '>':
        v += 1
    else:
        v = 0
    rights.append(v)

ans = 0

for l, r in zip(lefts, reversed(rights)):
    ans += max(l, r)

print(ans)
