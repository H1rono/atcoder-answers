import typing as tp

def split_s(s: str) -> tp.List[tp.Tuple[str, int]]:
    result = []
    c, *cs = s
    result.append((c, 1))
    for c in cs:
        prev_c, cnt = result[-1]
        if c == prev_c:
            result[-1] = (c, cnt + 1)
        else:
            result.append((c, 1))
    return result

# def parse_cmds(cmds: tp.List[tp.Tuple[str, int]]) -> tp.List[tp.Tuple[str, int]]:
#     parsed_rev = []
#     u_cmd_cnt = 0
#     for c, cnt in cmds[::-1]:
#         if c == 'U':
#             u_cmd_cnt += cnt
#             continue
#         cnt_ = cnt - u_cmd_cnt
#         if cnt_ > 0:
#             parsed_rev.append()

n, x = map(int, input().split())
cmds = split_s(input())

for c, cnt in cmds:
    if c == 'U':
        x = x >> cnt
    elif c == 'L':
        x = x << cnt
    else:
        x = x << cnt | (2 ** cnt - 1)

print(x)
