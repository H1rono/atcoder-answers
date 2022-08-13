#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_set>

using vint = std::vector<int>;
using Edge = std::pair<int, int>;
using Edges = std::vector<Edge>;

class UnionFind {
private:

public:
    std::vector<int> _parents, _size;

    UnionFind(int length)
    : _parents(length, 0), _size(length, 1) {
        for (int i = 0; i < length; ++i) {
            _parents[i] = i;
        }
    }

    int root(int u) {
        if (_parents[u] == u) return u;
        int r = root(_parents[u]);
        _parents[u] = r;
        return r;
    }

    bool equiv(int u, int v) {
        return root(u) == root(v);
    }

    void unite(int u, int v) {
        int u_root = root(u), v_root = root(v);
        if (u_root == v_root) return;
        _parents[u_root] = v_root;
        _size[v_root] += _size[u_root];
        _size[u_root] = 0;
    }

    int size(int u) {
        return _size[root(u)];
    }
};

void print_vint(const vint & v) {
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void solve(int n, int m, int e, const Edges & edges, int q, const vint & xs) {
    UnionFind uf(n + m + 1);

    for (int i = 0; i < m; ++i) {
        uf.unite(n + i, n + m);
    }

    vint xs_sorted = xs;
    std::sort(xs_sorted.begin(), xs_sorted.end());

    for (int i = 0; i < e; ++i) {
        auto i_ = std::lower_bound(xs_sorted.begin(), xs_sorted.end(), i);
        if (i == *i_) continue;
        auto [u, v] = edges[i];
        uf.unite(u, v);
    }

    vint answers(q, 0);
    for (int i = 0; i < q; ++i) {
        answers[q - i - 1] = uf.size(n + m) - m - 1;
        int x = xs[q - i - 1];
        auto [u, v] = edges[x];
        uf.unite(u, v);
    }

    for (int ans : answers) {
        std::cout << ans << std::endl;
    }
}

int main() {
    int n, m, e;
    std::cin >> n >> m >> e;
    Edges edges(e);
    for (int i = 0; i < e; ++i) {
        int a, b;
        std::cin >> a >> b;
        edges[i] = Edge(a - 1, b - 1);
    }
    int q;
    std::cin >> q;
    vint xs(q);
    for (int & x : xs) {
        std::cin >> x;
        x--;
    }
    solve(n, m, e, edges, q, xs);
}
