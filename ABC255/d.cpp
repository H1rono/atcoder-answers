#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using i64 = std::int64_t;

int main() {
    int n, queries;
    std::cin >> n >> queries;

    std::vector<i64> a(n, 0);
    for (int i = 0; i < n; ++i) {
        i64 v;
        std::cin >> v;
        a[i] = v;
    }
    std::sort(a.begin(), a.end());

    std::vector<i64> accum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        accum[i] = accum[i - 1] + a[i - 1];
    }

    auto index = [&](i64 x) -> int {
        int ng = -1, ok = n;
        while (ok - ng > 1) {
            int mid = (ok + ng) >> 1;
            if (a[mid] < x) {
                ng = mid;
            } else {
                ok = mid;
            }
        }
        return ok;
    };

    for (int q = 0; q < queries; ++q) {
        i64 x;
        std::cin >> x;
        // x > a[i] となる最大の i
        int i = index(x);
        int left = x * i - accum[i];
        int right = accum[n] - accum[i] - x * (n - i);
        i64 ans = left + right;
        std::cout << ans << std::endl;
    }
}
