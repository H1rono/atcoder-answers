n, k = map(int, input().split())
prices = sorted(map(int, input().split()))

def gen(len: int, min_: int):
    if len == 0:
        yield ()
        return
    for i in range(min_, n):
        for rest in gen(len - 1, i):
            yield (i, *rest)

billings = set()

for i, _ in enumerate(iter(object, None)):
    for p in gen(i + 1, 0):
        billings.add(sum(prices[j] for j in p))
    if len(billings) >= k:
        break

billings = sorted(billings)
print(billings[k - 1])
