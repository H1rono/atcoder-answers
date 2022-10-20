f = [1]

for i in range(1, 11):
    f.append(f[-1] * i)

n = int(input())
print(f[n])
