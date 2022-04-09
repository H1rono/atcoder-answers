from collections import defaultdict

class ReplaceList(list):
    def __init__(self, *args, replaces: dict = {}, **kwargs):
        super().__init__(*args, **kwargs)
        self._replaces = defaultdict(lambda: -1)
        self._replaces.update(replaces)

    def __getitem__(self, index_or_slice):
        v = super().__getitem__(index_or_slice)
        if isinstance(index_or_slice, slice):
            return v
        r = self._replaces[v]
        if r >= 0:
            return r
        return v

    def __str__(self) -> str:
        s = "["
        ln = len(self)
        for i in range(ln):
            s += str(self[i])
            if ln - i > 1:
                s += ", "
        return s + "]"

    def add_replace(self, key: int, value: int) -> None:
        self._replaces[key] = value

    def del_replace(self, key: int):
        try:
            del self._replaces[key]
        except:
            pass

ln = int(input())
nums = ReplaceList(map(int, input().split()))

def get_values(ls: list, i: int): # (int, int)
    return (ls[i], ls[ln - i - 1])

def dfs(repl_ls: ReplaceList, start: int, end: int) -> int:
    if start == end:
        return 0
    l, r = get_values(repl_ls, start)
    nxt = start + 1
    if l == r:
        return dfs(repl_ls, nxt, end)
    repl_ls.add_replace(l, r)
    res_l = dfs(repl_ls, nxt, end)
    repl_ls.del_replace(l)
    repl_ls.add_replace(r, l)
    res_r = dfs(repl_ls, nxt, end)
    repl_ls.del_replace(r)
    mi = 0
    if res_l < res_r:
        mi = res_l
        repl_ls.add_replace(l, r)
    else:
        mi = res_r
        repl_ls.add_replace(r, l)
    return mi + 1

print(dfs(nums, 0, ln >> 1))

