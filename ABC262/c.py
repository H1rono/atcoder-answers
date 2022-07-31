num = int(input())
perm = [0] + list(map(int, input().split()))
self_ref = 0
cross_ref = 0


for i in range(1, num + 1):
    self_ref += perm[i] == i
    j = perm[i]
    cross_ref += j > i and perm[j] == i


ans = max(self_ref * (self_ref - 1) // 2, 0) + cross_ref
print(ans)
