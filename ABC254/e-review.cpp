#include <iostream>
#include <vector>
#include <cstdint>

using u64 = std::uint64_t;

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n, std::vector<int>());
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int queries;
    std::cin >> queries;
    std::vector<int> dist(n, 4);
    for (int _ = 0; _ < queries; ++_) {
        int x, k;
        std::cin >> x >> k;
        x--;
        std::vector<int> visits{x};
        dist[x] = 0;
        for (int i = 0; i < visits.size(); ++i) {
            int current = visits[i];
            for (int j : graph[current]) {
                int d = dist[current] + 1;
                if (d > k || dist[j] != 4) continue;
                dist[j] = d;
                visits.push_back(j);
            }
        }
        u64 ans = 0;
        for (int v : visits) {
            dist[v] = 4;
            ans += v + 1;
        }
        std::cout << ans << std::endl;
    }
}