s = input()

t = []
for c in s:
    if c == 'R':
        t = t[::-1]
    else:
        if t and t[-1] == c:
            t.pop()
        else:
            t.append(c)

print("".join(t))

