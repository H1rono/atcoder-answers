from collections import defaultdict

person_num = int(input())
persons = [tuple(input().split()) for _ in range(person_num)]
name_counts = defaultdict(lambda: 0)

for family, given in persons:
    name_counts[family] += 1
    name_counts[given]  += 1

for family, given in persons:
    family_ok = name_counts[family] == 1
    given_ok  = name_counts[given]  == 1
    if not (family_ok or given_ok):
        print("No")
        break
else:
    print("Yes")
