origin = int(input().strip())


for year in range(origin, origin + 4):
	if (year & 3) == 2:
		print(year)
		break
