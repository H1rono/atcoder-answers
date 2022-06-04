dp = []
n = int(input())

for i in range(n):
    nl = []
    for j in range(i + 1):
        if j in (0, i):
            nl.append(1)
            continue
        a = dp[i - 1][j - 1] + dp[i - 1][j]
        nl.append(a)
    dp.append(nl)
    print(" ".join(map(str, nl)))
