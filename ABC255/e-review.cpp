#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <unordered_map>

using i64 = std::int64_t;
using vi64 = std::vector<i64>;

int index(const vi64 & v, i64 x) {
    int l = -1, r = v.size();
    while (r - l > 1) {
        int mid = (r + l) >> 1;
        if (v[mid] < x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return r;
}

bool contains(const vi64 & v, i64 x) {
    int i = index(v, x);
    return v[i] == x;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vi64 S(n - 1, 0), X(m, 0);
    for (i64 & s : S) std::cin >> s;
    for (i64 & x : X) {
        std::cin >> x;
    }
    vi64 base_a(n, 0);
    for (int i = 1; i < n; ++i) {
        base_a[i] = S[i - 1] - base_a[i - 1];
    }
    // luky_counts[x] := 初項が x の時の ラッキーナンバーの数
    std::unordered_map<i64, i64> lucky_counts{};
    // cond[i][j] := A[i] = X[j] となるための初項
    std::vector<vi64> cond{};
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            // A[i] = X[j]の場合
            // 初項 x
            i64 x = (i & 1 ? -1 : 1) * (base_a[i - 1] - X[j]);
            lucky_counts[x]++;
        }
    }
    i64 ans = 0;
    for (auto [x, count] : lucky_counts) {
        ans = std::max(ans, count);
    }
    std::cout << ans << std::endl;
}
