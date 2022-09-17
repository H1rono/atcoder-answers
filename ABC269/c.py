n = int(input())
digits = [i for i in range(n.bit_length()) if n & (1 << i)]
cands = [0]

for i in digits:
    cands += [c | (1 << i) for c in cands]

print("\n".join(map(str, cands)))
