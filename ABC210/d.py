row_num, col_num, rail_cost_per_dist = map(int, input().split())

station_costs = []
for r in range(row_num):
    station_costs.append(list(map(int, input().split())))

min_cost = station_costs[0][0] + station_costs[1][0] + rail_cost_per_dist

for r1, c1 in ((r, c) for r in range(row_num) for c in range(col_num)):
    if r1 == row_num - 1 and c1 == col_num - 1:
        break
    for r2 in range(r1, row_num):
        row_rail_cost = rail_cost_per_dist * (r2 - r1)
        if row_rail_cost > min_cost:
            break
        for c2 in range(c1, col_num):
            rail_cost = row_rail_cost + rail_cost_per_dist * (c2 - c1)
            if not rail_cost:
                continue
            if rail_cost > min_cost:
                break
            min_cost = min(min_cost, station_costs[r1][c1] + station_costs[r2][c2] + rail_cost)

print(min_cost)

