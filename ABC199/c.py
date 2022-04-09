class Ptrs:
    def __init__(self, ln: int) -> None:
        self.ln = ln
        self.left = list(range(ln))
        self.right = list(range(ln, ln * 2))

    def __len__(self):
        return self.ln

    def __getitem__(self, i):
        if i < self.ln:
            return self.left[i]
        return self.right[i - self.ln]

    def __setitem__(self, i, val):
        if i < self.ln:
            self.left[i] = val
        else:
            self.right[i - self.ln] = val

str_len = int(input())
tar_str = input()

ptrs = Ptrs(str_len)

query_len = int(input())

for i in range(query_len):
    t, a, b = map(int, input().split())
    if t == 1:
        a -= 1
        b -= 1
        ptrs[a], ptrs[b] = ptrs[b], ptrs[a]
    else:
        ptrs.left, ptrs.right = ptrs.right, ptrs.left

res = "".join(map(tar_str.__getitem__, ptrs.left + ptrs.right))
print(res)

