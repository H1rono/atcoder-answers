#include <iostream>
#include <vector>

using LL = long long;
using LLvec = std::vector<LL>;

void upd(LL &m, LLvec &v, int s, int t, const LL &p) {
    int l = v.size();
    if (l <= s) {
        for (int i = l; i < s; ++i) {
            v.push_back(0);
        }
    }
    for (int i = s; i < t; ++i) {
        if (l <= i) {
            v.push_back(p);
        } else {
            v[i] += p;
        }
        m = m < v[i] ? v[i] : m;
    }
}

int main() {
    LLvec V{};
    int N;
    LL W;
    std::cin >> N >> W;
    int s, t;
    LL p, ma = 0ll;
    for (int i = 0; i < N; ++i) {
        std::cin >> s >> t >> p;
        upd(ma, V, s, t, p);
        if (W < ma) {
            std::cout << "No\n";
            return 0;
        }
    }
    std::cout << "Yes\n";
}