def sorted_list_index(l: list, value: int) -> int:
    left, right = -1, len(l)
    while right - left > 1:
        mid = (left + right) >> 1
        if value < l[mid]:
            right = mid
        else:
            left = mid
    return right

nums_len, query_len = map(int, input().split())
nums = sorted(map(int, input().split()))

space_sums = [nums[0] - 1]
for i in range(1, nums_len):
    diff = nums[i] - nums[i - 1] - 1
    s_sum = diff + space_sums[-1]
    space_sums.append(s_sum)

def process_query(query: int) -> int:
    index = sorted_list_index(space_sums, query - 1) - 1
    if index < 0:
        return query
    return nums[index] + query - space_sums[index]

for i in range(query_len):
    query = int(input())
    print(process_query(query))


