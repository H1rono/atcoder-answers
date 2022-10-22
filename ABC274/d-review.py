from typing import List
from collections import deque


def solve_axis(goal: int, ps: List[int]) -> bool:
    l = len(ps)
    seen = [set() for _ in range(l + 1)]
    que = deque()
    que.append((0, 0))
    while que:
        i, p = que.popleft()
        if p in seen[i]:
            continue
        if i == l:
            if goal == p:
                return True
            continue
        seen[i].add(p)
        dp = ps[i]
        que.append((i + 1, p + dp))
        que.append((i + 1, p - dp))
    return False



def main():
    _, x, y = map(int, input().split())
    nums = map(int, input().split())
    xs, ys = [], []
    for i, a in enumerate(nums):
        if not i % 2:
            xs.append(a)
        else:
            ys.append(a)
    if solve_axis(x - xs[0], xs[1:]) and solve_axis(y, ys):
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()
