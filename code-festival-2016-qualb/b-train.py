# (int, int, int, str) -> [str]
def solve(n, a, b, s):
    ans = []
    qualified_domestic, qualified_foreign = 0, 0
    for c in s:
        qualified = False
        qual_condition_base = qualified_domestic + qualified_foreign < a + b
        if c == 'a':
            if qual_condition_base:
                qualified = True
                qualified_domestic += 1
        elif c == 'b':
            if qual_condition_base and qualified_foreign < b:
                qualified = True
                qualified_foreign += 1
        ans.append('Yes' if qualified else 'No')
    return ans


def main():
    n, a, b = map(int, input().split())
    s = input()
    print(*solve(n, a, b, s), sep='\n')


if __name__ == '__main__':
    main()
