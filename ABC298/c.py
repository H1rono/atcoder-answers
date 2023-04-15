n = int(input())
q = int(input())
boxes = [list() for _ in range(n)]
box_of = {}

for _ in range(q):
    line = list(map(int, input().split()))
    if line[0] == 1:
        i, j = line[1:]
        j -= 1
        boxes[j].append(i)
        if i not in box_of:
            box_of[i] = set()
        box_of[i].add(j)
    elif line[0] == 2:
        j = line[1]
        j -= 1
        print(*sorted(boxes[j]))
    elif line[0] == 3:
        i = line[1]
        bs = box_of.get(i, set())
        print(*map(lambda x: x + 1, sorted(bs)))
