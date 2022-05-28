w = int(input())
w_3 = w // 3
a_ = []
g = [False for i in range(w_3 + 1)]

n = 2
s = "1 2"

for i in range(1, w_3 + 1):
    if g[i]:
        continue
    g[i] = True
    ln = len(a_)
    for j in range(ln):
        v = i + a_[j]
        if v > w_3:
            break
        g[v] = True
    a_.append(i)
    n += 1
    s += f" {i}"

print(n)
print(s)
