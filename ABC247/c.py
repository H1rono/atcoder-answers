note = {}
n = int(input())
for i in range(1, n + 1):
    s_i = " 1 " if i == 1 else note[i - 1] + str(i) + note[i - 1]
    note[i] = s_i

print(note[n].strip())