import sys


def sorted_find(arr, num):
    left, right = 0, len(arr) - 1
    if num <= arr[left]:
        return left
    elif arr[right] <= num:
        return right + 1
    while left + 1 != right:
        mid = (left + right) // 2
        mid_v = arr[mid]
        if mid_v == num:
            return mid
        elif mid_v < num:
            left = mid
        elif num < mid_v:
            right = mid
    return left


def sorted_insert(arr, num):
    left, right = 0, len(arr) - 1
    if not arr:
        arr.append(num)
        return
    elif num <= arr[left]:
        arr.insert(num, 0)
        return
    elif arr[right] <= num:
        arr.append(num)
        return
    while left + 1 != right:
        mid = (left + right) // 2
        mid_v = arr[mid]
        if mid_v == num:
            arr.insert(num, mid)
            return
        elif mid_v < num:
            left = mid
        elif num < mid_v:
            right = mid
    arr.insert(num, right)


n = int(input())
available_nums = list(range(1, 2 * n + 2))
while True:
    print(available_nums[0])
    available_nums = available_nums[1:]
    sys.stdout.flush()
    decl = int(input())
    if decl == 0:
        break
    i = sorted_find(available_nums, decl)
    available_nums.pop(i)

