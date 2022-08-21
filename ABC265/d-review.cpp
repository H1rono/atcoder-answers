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
    for (int x = 0; x < n; ++x) {
        int y = find_index(x, p);
        if (sum_of(x, y) != p) {
            continue;
        }
        int z = find_index(y, q);
        if (sum_of(y, z) != q) {
            continue;
        }
        int w = find_index(z, r);
        if (sum_of(z, w) != r) {
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
