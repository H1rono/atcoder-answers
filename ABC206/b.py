price = int(input())

left, right = 0, pow(10, 5)
while right - left > 1:
    mid = (right + left) >> 1
    p = mid * (mid + 1) >> 1
    if p < price:
        left = mid
    else:
        right = mid

print(right)

