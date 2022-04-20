from collections import defaultdict

def search(ls, x):
    ng, ok = -1, len(ls)
    while ok - ng > 1:
        mid = (ok + ng) >> 1
        if ls[mid] < x:
            ng = x
        else:
            ok = mid
    return ok

n = int(input())
a_s = list(map(int, input().split()))

a_tree = defaultdict(lambda: [])
for i, a in enumerate(a_s, 1):
    a_tree[a].append(i)

q = int(input())
for i in range(q):
    l, r, x = map(int, input().split())
    ls = a_tree[x]
    l_, r_ = search(ls, l), search(ls, r)
    ans = r_ - l_ + (r == r_)
    print(ans)
