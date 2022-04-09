#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using ivector = std::vector<int>;
using iset = std::set<int>;

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<iset> val_map(n);

    auto mex = [&](int begin, int end) -> int {
        for (int val = 0; val < n; val++) {
            iset indexes = val_map[val];
            bool contains = false;
            for (int i : indexes) {
                if (begin <= i && i < end) {
                    contains = true;
                    break;
                }
            }
            if (!contains) return val;
        }
        return 0;
    };

    for (int i = 0; i < n; i++) {
        int v; std::cin >> v;
        val_map[v].insert(i);
    }

    int min_mex = mex(0, m);
    for (int i = 1; i <= m; i++) {
        int mx = mex(i, m + i);
        min_mex = std::min(mx, min_mex);
    }
    std::cout << min_mex << std::endl;
    return 0;
}