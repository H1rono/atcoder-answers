from itertools import chain

ls_len, dist_max = map(int, input().split())
nums_a = map(int, input().split())
nums_b = map(int, input().split())
all_nums = sorted(chain(nums_a, nums_b))

chain_count = 1
num_prev = all_nums[0]

for num_current in all_nums[1:]:
    dist = num_current - num_prev
    if dist <= dist_max:
        chain_count += 1
        if chain_count >= ls_len:
            print("Yes")
            break
    else:
        chain_count = 1
    num_prev = num_current
else:
    print("No")

