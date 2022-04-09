input()
vals = map(int, input())
it = map(lambda a: (bool(a[0] & 1), bool(a[1])), enumerate(vals))
for p, b in it:
    if b:
        print("Aoki" if p else "Takahashi")
        break