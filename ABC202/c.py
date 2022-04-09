def sorted_list_index(ls: list, value) -> int:
    ng = -1
    ok = len(ls)
    while ok - ng > 1:
        mid = int((ng + ok) / 2)
        if ls[mid] > value:
            ok = mid
        else:
            ng = mid
    return ok

if __name__ == "__main__":
    N = int(input())
    A = sorted(list(map(int, input().split())))
    B = list(map(int, input().split()))
    C = map(int, input().split())

    ans = 0

    for i in C:
        b = B[i - 1]
        a_beg = sorted_list_index(A, b - 1)
        a_end = sorted_list_index(A, b)
        ans += a_end - a_beg

    print(ans)

