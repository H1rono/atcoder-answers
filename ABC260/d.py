n, k = map(int, input().split())
p = list(map(int, input().split()))
eaten_turn = [-1] * n
field = []

for i, num in enumerate(p):
    pile_index = None
    pile_top_cmp = -1
    for j, pile in enumerate(field):
        pile_top = pile[-1]
        if pile_top < num:
            continue
        if pile_top_cmp is None or pile_top < pile_top_cmp:
            pile_top_cmp = pile_top
            pile_index = j
    if pile_index is None:
        field.append([num])
        continue
    pile = field[pile_index]
    pile.append(num)
    if len(pile) == k:
        for pnum in pile:
            eaten_turn[pnum - 1] = i + 1
        field.pop(pile_index)


print("\n".join(map(str, eaten_turn)))

