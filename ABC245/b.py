length = int(input())
nums = set(map(int, input().split()))
for i, _ in enumerate(iter(object, None)):
    if i not in nums:
        print(i)
        break
