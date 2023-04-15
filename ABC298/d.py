from collections import deque

q = int(input())
que = deque()
que.append(1)

for _ in range(q):
    line = list(map(int, input().split()))
    if line[0] == 1:
        x = line[1]
        que.append(x)
        if len(que) > 20:
            n = int("".join(map(str, que)) or "0")
            n %= 998244353
            que = deque(map(int, str(n)))
    elif line[0] == 2:
        que.popleft()
    elif line[0] == 3:
        n = int("".join(map(str, que)))
        print(n % 998244353)
