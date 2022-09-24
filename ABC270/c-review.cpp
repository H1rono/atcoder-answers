#include <iostream>
#include <vector>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    x--; y--;
    std::vector<std::vector<int>> graph(n, std::vector<int>{});
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    std::vector<int> dist(n, 0);
    std::vector<bool> seen(n, false);
    seen[x] = true;
    std::vector<int> que{x};
    for (int i = 0; i < que.size(); ++i) {
        int u = que[i];
        int nd = dist[u] + 1;
        for (int v : graph[u]) {
            if (seen[v]) continue;
            dist[v] = nd;
            que.push_back(v);
            seen[v] = true;
        }
    }
    std::vector<int> result{y};
    while (1) {
        int u = result.back();
        int nd = dist[u] - 1;
        for (int v : graph[u]) {
            if (dist[v] == nd) {
                result.push_back(v);
                break;
            }
        }
        if (nd == 0) break;
    }
    for (int i = result.size() - 1; i > 0; --i) {
        std::cout << (result[i] + 1) << ' ';
    }
    std::cout << (result[0] + 1) << std::endl;
}
