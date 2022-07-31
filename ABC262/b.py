node_num, edge_num = map(int, input().split())
graph = [set() for _ in range(node_num)]


for _ in range(edge_num):
    i, j = map(int, input().split())
    i -= 1
    j -= 1
    graph[i].add(j)
    graph[j].add(i)


it = (
    (a, b, c)
    for a in range(node_num)
    for b in range(a + 1, node_num)
    for c in range(b + 1, node_num)
)
ans = 0


for a, b, c in it:
    ans += all([
        b in graph[a], # a -> b
        c in graph[b], # b -> c
        a in graph[c]  # c -> a
    ])


print(ans)
