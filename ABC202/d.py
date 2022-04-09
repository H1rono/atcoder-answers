from math import comb

def solve(a_num: int, b_num: int, k: int) -> str:
    if not (a_num and b_num):
        return 'a' * a_num + 'b' * b_num
    s = a_num + b_num
    # aが先頭
    cmb_a = comb(s - 1, b_num)
    if k <= cmb_a:
        # 先頭はa
        return 'a' + solve(a_num - 1, b_num, k)
    else:
        # 先頭はb
        return 'b' + solve(a_num, b_num - 1, k - cmb_a)

print(solve(*map(int, input().split())))

