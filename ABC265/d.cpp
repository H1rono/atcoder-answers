#include <iostream>
#include <vector>
#include <cstdint>
#include <utility>

using u64 = std::uint64_t;
using u8 = std::uint8_t;
using pair_ii = std::pair<int, int>;

bool solve(int n, u64 p, u64 q, u64 r, const std::vector<u64>& a) {
    std::vector<u64> a_accum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        a_accum[i + 1] = a_accum[i] + a[i];
    }
    auto sum_of = [&](int l, int r) {
        return a_accum[r] - a_accum[l];
    };
    auto find_index = [&](int begin, u64 sum) {
        int ng = begin, ok = n;
        while (ng + 1 < ok) {
            int mid = (ng + ok) / 2;
            if (sum_of(begin, mid) < sum) {
                ng = mid;
            } else {
                ok = mid;
            }
        }
        return ok;
    };
    // std::vector<bool> y_cand(n + 1, false), z_cand(n + 1, false);//, w_cand(n + 1, false);
    // std::vector<pair_ii> xy_cands{}, yz_cands{}, zw_cands{};
    // for (int i = 0; i <= n; i++) {
    //     int y_ = find_index(i, p);
    //     if (sum_of(i, y_) == p) {
    //         xy_cands.push_back({i, y_});
    //         // y_cand[y_] = true;
    //     }
    //     // if (!y_cand[i]) continue;
    //     int z_ = find_index(i, q);
    //     if (sum_of(i, z_) == q) {
    //         yz_cands.push_back({i, z_});
    //         // z_cand[z_] = true;
    //     }
    //     // if (!z_cand[i]) continue;
    //     int w_ = find_index(i, r);
    //     if (sum_of(i, w_) == r) {
    //         zw_cands.push_back({i, w_});
    //     }
    // }
    // for (auto [x, y] : xy_cands) {
    //     for (auto [y_, z] : yz_cands) {
    //         if (y != y_) {
    //             continue;
    //         }
    //         for (auto [z_, w] : zw_cands) {
    //             if (z != z_) {
    //                 continue;
    //             }
    //             return true;
    //         }
    //     }
    // }
    for (int i = 0; i < n; ++i) {
        int y = find_index(i, p);
        if (sum_of(i, y) != p) {
            continue;
        }
        int z = find_index(i, q);
        if (sum_of(y, z) != q) {
            continue;
        }
        int w_ = find_index(z, r);
        if (sum_of(z, w_) != r) {
            continue;
        }
        return true;
    }
    return false;
}

int main() {
    int n;
    u64 p, q, r;
    std::cin >> n >> p >> q >> r;
    std::vector<u64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::cout << (solve(n, p, q, r, a) ? "Yes" : "No") << std::endl;
}
